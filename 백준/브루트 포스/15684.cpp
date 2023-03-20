#include <iostream>
#include <algorithm>
using namespace std;

bool connected[100][100];
// n : 세로줄, m : 가로줄 개수, h : 가로 위치의 개수
int n, m, h;
int answer = INT32_MAX;

bool isCorrect()
{
	for (int i = 1; i <= n; i++)
	{
		int current = i;

		for (int j = 1; j <= h; j++)
		{
			if (connected[current][j])
			{
				current++;
			}
			else if (connected[current - 1][j])
			{
				current--;
			}
		}

		if (current != i)
		{
			return false;
		}
	}

	return true;
}

void func(int index, int cnt)
{
	if (cnt >= 4)
	{
		return;
	}

	if (isCorrect())
	{
		answer = min(answer, cnt);
		return;
	}

	for (int i = index; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (connected[j][i])
			{
				continue;
			}
			if (connected[j - 1][i])
			{
				continue;
			}
			if (connected[j + 1][i])
			{
				continue;
			}

			connected[j][i] = true;
			func(i, cnt + 1);
			connected[j][i] = false;
		}
	}
}

int main()
{
	cin >> n >> m >> h;
	
	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;

		connected[b][a] = true;
	}

	func(1, 0);

	if (answer == INT32_MAX)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << answer << '\n';
	}

	return 0;
}