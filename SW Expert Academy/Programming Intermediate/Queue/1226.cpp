#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int maze[16][16];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int bfs(int startY, int startX)
{
	queue<pair<int, int>> q;
	q.push(make_pair(startY, startX));
	maze[startY][startX] = 1;

	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int tempY = temp.first + dy[i];
			int tempX = temp.second + dx[i];

			if (maze[tempY][tempX] == 0)
			{
				maze[tempY][tempX] = 1;
				q.push(make_pair(tempY, tempX));
			}
			else if (maze[tempY][tempX] == 3)
			{
				return 1;
			}
		}
	}

	return 0;
}

int main()
{
	int test_case;
	int testNum;

	for (test_case = 1; test_case <= 10; test_case++)
	{
		char input;
		int startY, startX;
		cin >> testNum;

		// 미로 입력 받기
		for (int y = 0; y < 16; y++)
		{
			for (int x = 0; x < 16; x++)
			{
				cin >> input;
				int temp = input - '0';

				if (temp == 2)
				{
					startY = y;
					startX = x;
				}
				maze[y][x] = temp;
			}
		}

		cout << "#" << test_case << " " << bfs(startY, startX) << '\n';
	}

	return 0;
}