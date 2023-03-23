#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 20

int r, c;

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };
int result = -1;

char board[MAX][MAX];
bool visited[26];

bool inRange(int y, int x)
{
	if (0 <= y && y < r && 0 <= x && x < c)
	{
		return true;
	}
	return false;
}

void dfs(int y, int x, int cnt)
{
	result = max(result, cnt);

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (inRange(nextY, nextX))
		{
			char next = board[nextY][nextX];

			if (!visited[next - 'A'])
			{
				visited[next - 'A'] = true;
				dfs(nextY, nextX, cnt + 1);
				visited[next - 'A'] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	for (int y = 0; y < r; y++)
	{
		for (int x = 0; x < c; x++)
		{
			cin >> board[y][x];
		}
	}

	visited[board[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << result << '\n';

	return 0;
}