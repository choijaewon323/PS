#include <iostream>
using namespace std;

#define N 0
#define S 1

#define UP 0
#define RIGHT 2
#define DOWN 4
#define LEFT 6

#define CLOCK 1
#define COUNTERCLOCK -1
#define NO 0

int gear[1001][8];
int rotation[1001];
int t;

void rotFunc(int num, int direction)
{
	if (direction == COUNTERCLOCK)
	{
		int di[8] = { 1,2,3,4,5,6,7,0 };
		int temp[8];

		for (int i = 0; i < 8; i++)
		{
			temp[i] = gear[num][di[i]];
		}

		for (int i = 0; i < 8; i++)
		{
			gear[num][i] = temp[i];
		}
	}
	else if (direction == CLOCK)
	{
		int di[8] = { 7,0,1,2,3,4,5,6 };
		int temp[8];

		for (int i = 0; i < 8; i++)
		{
			temp[i] = gear[num][di[i]];
		}

		for (int i = 0; i < 8; i++)
		{
			gear[num][i] = temp[i];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k;
	int result = 0;

	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char input;

			cin >> input;
			gear[i][j] = input - '0';
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int num, direction;

		for (int j = 0; j <= t; j++)
		{
			rotation[j] = 0;
		}

		cin >> num >> direction;
		rotation[num] = direction;

		// 오른쪽 검사
		for (int r = num + 1; r <= t; r++)
		{
			int prevRot = rotation[r - 1];
			int prevRight = gear[r - 1][RIGHT];

			if (prevRight != gear[r][LEFT])
			{
				if (prevRot == CLOCK)
				{
					rotation[r] = COUNTERCLOCK;
				}
				else if (prevRot == COUNTERCLOCK)
				{
					rotation[r] = CLOCK;
				}
				else if (prevRot == NO)
				{
					rotation[r] = NO;
				}
			}
			else
			{
				rotation[r] = NO;
			}
		}

		// 왼쪽 검사
		for (int l = num - 1; l >= 1; l--)
		{
			int prevRot = rotation[l + 1];
			int prevLeft = gear[l + 1][LEFT];

			if (prevLeft != gear[l][RIGHT])
			{
				if (prevRot == CLOCK)
				{
					rotation[l] = COUNTERCLOCK;
				}
				else if (prevRot == COUNTERCLOCK)
				{
					rotation[l] = CLOCK;
				}
				else if (prevRot == NO)
				{
					rotation[l] = NO;
				}
			}
			else
			{
				rotation[l] = NO;
			}
		}

		for (int j = 1; j <= t; j++)
		{
			rotFunc(j, rotation[j]);
		}
	}

	for (int i = 1; i <= t; i++)
	{
		if (gear[i][UP] == S)
		{
			result++;
		}
	}

	cout << result << '\n';

	return 0;
}