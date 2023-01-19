#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

#define DOWN	0
#define LEFT	1
#define RIGHT	2

using namespace std;

int matrix[102][102];

int main(int argc, char **argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		vector<pair<int, int>> startPoint;
		int testNum;
		int tempY, tempX;
		int trace;
		int startX;
		int result = 10000000;
		int resultX;
		int state;
		cin >> testNum;

		for (int y = 1; y <= 100; y++)
		{
			for (int x = 1; x <= 100; x++)
			{
				cin >> matrix[y][x];
			}
		}

		for (int i = 1; i <= 100; i++)
		{
			if (matrix[1][i])
			{
				startPoint.push_back(make_pair(1, i));
			}
		}

		for (auto start : startPoint)
		{
			tempY = start.first;
			tempX = start.second;
			startX = start.second;
			trace = 0;
			state = DOWN;

			while (tempY != 100)
			{
				trace++;
				if (state == DOWN)
				{
					if (matrix[tempY][tempX - 1])	// 왼쪽 가능
					{
						tempX--;
						state = LEFT;
					}
					else if (matrix[tempY][tempX + 1])	// 오른쪽 가능
					{
						tempX++;
						state = RIGHT;
					}
					else
					{
						tempY++;
					}
				}
				else if (state == LEFT)
				{
					if (!matrix[tempY][tempX - 1])	// 진행 불가능
					{
						tempY++;
						state = DOWN;
					}
					else
					{
						tempX--;
					}
				}
				else if (state == RIGHT)
				{
					if (!matrix[tempY][tempX + 1])	// 진행 불가능
					{
						tempY++;
						state = DOWN;
					}
					else
					{
						tempX++;
					}
				}
 			}

			if (result > trace)
			{
				result = trace;
				resultX = startX;
			}
		}

		cout << "#" << test_case << " " << resultX - 1 << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}