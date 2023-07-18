#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define UP			0
#define UPRIGHT		1
#define RIGHT		2
#define DOWNRIGHT	3
#define DOWN		4
#define DOWNLEFT	5
#define LEFT		6
#define UPLEFT		7

typedef struct _fireball
{
	int r;
	int c;
	int m;
	int s;
	int d;
} fireball;

vector<vector<vector<fireball>>> matrix;	// 격자
int n;	// 격자 크기
int f;	// fireball count
int k;	// command count

bool moveFunc(fireball& present)
{
	int direction = present.d;
	int startR = present.r;
	int startC = present.c;
	int speed = present.s;
	int endR = startR;
	int endC = startC;

	switch (direction)
	{
	case UP:
		endR = (startR - speed) % n;
		if (endR < 0)
		{
			endR += n;
		}
		break;

	case UPRIGHT:
		endR = (startR - speed) % n;
		if (endR < 0)
		{
			endR += n;
		}
		endC = (startC + speed) % n;
		break;

	case RIGHT:
		endC = (startC + speed) % n;
		break;
	
	case DOWNRIGHT:
		endR = (startR + speed) % n;
		endC = (startC + speed) % n;
		break;
	
	case DOWN:
		endR = (startR + speed) % n;
		break;
	
	case DOWNLEFT:
		endR = (startR + speed) % n;
		endC = (startC - speed) % n;
		if (endC < 0)
		{
			endC += n;
		}
		break;
	
	case LEFT:
		endC = (startC - speed) % n;
		if (endC < 0)
		{
			endC += n;
		}
		break;
	
	case UPLEFT:
		endR = (startR - speed) % n;
		if (endR < 0)
		{
			endR += n;
		}
		endC = (startC - speed) % n;
		if (endC < 0)
		{
			endC += n;
		}
		break;
	}
	
	present.r = endR;
	present.c = endC;

	return true;
}

void move()
{
	vector<vector<vector<fireball>>> tempMatrix(51, vector<vector<fireball>>(51, vector<fireball>()));

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (matrix[y][x].empty())
			{
				continue;
			}

			for (fireball temp : matrix[y][x])
			{
				bool result;

				result = moveFunc(temp);

				if (result)
				{
					tempMatrix[temp.r][temp.c].push_back(temp);
				}
			}
		}
	}

	matrix = tempMatrix;
}

void sumAndDivide()
{
	vector<vector<vector<fireball>>> tempMatrix(51, vector<vector<fireball>>(51, vector<fireball>()));

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (matrix[y][x].size() == 1)
			{
				tempMatrix[y][x].push_back(matrix[y][x].front());
			}

			if (matrix[y][x].size() >= 2)
			{
				fireball result;
				int size = matrix[y][x].size();
				int mSum = 0;
				int sSum = 0;
				int direction = matrix[y][x].front().d;
				bool correct = true;
				int oddOrEven = -1;

				if (direction % 2 == 0)
				{
					oddOrEven = 0;
				}
				else
				{
					oddOrEven = 1;
				}

				for (auto& temp : matrix[y][x])
				{
					mSum += temp.m;
					sSum += temp.s;

					if (oddOrEven == 0)	// even
					{
						if (temp.d % 2 == 1)
						{
							correct = false;
						}
					}
					else			// odd
					{
						if (temp.d % 2 == 0)
						{
							correct = false;
						}
					}
				}

				matrix[y][x].clear();

				if (mSum / 5 != 0)
				{
					if (correct)
					{
						int ds[] = { 0, 2, 4, 6 };

						for (int i = 0; i < 4; i++)
						{
							tempMatrix[y][x].push_back({ y, x, mSum / 5, sSum / size, ds[i] });
						}
					}
					else
					{
						int ds[] = { 1,3,5,7 };

						for (int i = 0; i < 4; i++)
						{
							tempMatrix[y][x].push_back({ y, x, mSum / 5, sSum / size, ds[i] });
						}
					}
				}
			}
		}
	}

	matrix = tempMatrix;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int answer = 0;

	cin >> n >> f >> k;

	matrix = vector<vector<vector<fireball>>>(51, vector<vector<fireball>>(51, vector<fireball>()));

	for (int i = 0; i < f; i++)
	{
		int r, c, m, d, s;	// 행, 열, 질량, 방향, 속력

		cin >> r >> c >> m >> s >> d;

		matrix[r - 1][c - 1].push_back({ r - 1, c - 1, m, s, d });
	}

	for (int i = 0; i < k; i++)
	{
		move();

		sumAndDivide();
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			for (fireball& temp : matrix[y][x])
			{
				answer += temp.m;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}