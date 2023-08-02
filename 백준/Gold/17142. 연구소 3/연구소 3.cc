#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 1000000

vector<pair<int, int>> virus;
int lab[50][50];
int N, M;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

bool inRange(int y, int x)
{
	if (0 <= y && y < N && 0 <= x && x < N)
	{
		return true;
	}
	return false;
}

int bfs(vector<int> index)
{
	queue<pair<int, int>> q;
	vector<vector<int>> visited(N, vector<int>(N, 0));

	for (int i = 0; i < index.size(); i++)
	{
		pair<int, int> v = virus[index[i]];

		visited[v.first][v.second] = 1;
		q.push({ v.first, v.second });
	}

	while (!q.empty())
	{
		pair<int, int> present = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = present.first + dy[i];
			int nx = present.second + dx[i];

			if (inRange(ny, nx) && visited[ny][nx] == 0 && lab[ny][nx] != 1)
			{
				q.push({ ny, nx });
				visited[ny][nx] = visited[present.first][present.second] + 1;
			}
		}
	}

	int result = -1;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (visited[y][x] == 0 && lab[y][x] == 0)
			{
				return MAX;
			}

			if (visited[y][x] == 0 && lab[y][x] == 1)
			{
				continue;
			}

			if (lab[y][x] == 2)
			{
				continue;
			}

			result = max(visited[y][x], result);
		}
	}

	if (result == -1)
	{
		return 0;
	}
	return result - 1;
}

int solution(int M, vector<int> index)
{
	if (index.size() == M)
	{
		return bfs(index);
	}

	if (index.empty())
	{
		int result = MAX;
		for (int i = 0; i < virus.size(); i++)
		{
			index.push_back(i);
			result = min(solution(M, index), result);
			index.pop_back();
		}

		if (result == MAX)
		{
			return -1;
		}
		else
		{
			return result;
		}
	}

	int result = MAX;
	for (int i = index.back() + 1; i < virus.size(); i++)
	{
		index.push_back(i);
		result = min(solution(M, index), result);
		index.pop_back();
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> lab[y][x];

			if (lab[y][x] == 2)
			{
				virus.push_back({ y, x });
			}
		}
	}

	vector<int> index;
	int result = solution(M, index);

	cout << result << '\n';

	return 0;
}