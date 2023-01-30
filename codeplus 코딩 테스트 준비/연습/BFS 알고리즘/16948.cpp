#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n;
int isVisited[200][200];
int dy[] = { -2, -2, 0, 0, 2, 2 };
int dx[] = { -1, 1, -2, 2, -1, 1 };

int bfs(int startR, int startC, int desR, int desC)
{
	queue<pair<int, int>> q;
	isVisited[startR][startC] = 1;
	q.push(make_pair(startR, startC));

	while (!q.empty())
	{
		int tempY, tempX;
		pair<int, int> temp = q.front();
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			tempY = temp.first + dy[i];
			tempX = temp.second + dx[i];

			if (tempY == desR && tempX == desC)
			{
				return isVisited[temp.first][temp.second] + 1;
			}

			if (tempY >= 0 && tempY < n && tempX >= 0 && tempX < n && 
				isVisited[tempY][tempX] == 0)
			{
				isVisited[tempY][tempX] = isVisited[temp.first][temp.second] + 1;
				q.push(make_pair(tempY, tempX));
			}
		}
	}

	return 0;
}

int main()
{
	int r1, c1, r2, c2;
	
	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;

	cout << bfs(r1, c1, r2, c2) - 1 << '\n';

	return 0;
}