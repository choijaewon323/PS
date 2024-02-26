#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, H;

// z, y, x
int box[100][100][100];

int dz[] = { 0, 0, 0, 0, 1, -1 };
int dy[] = { -1, 0, 1, 0, 0, 0 };
int dx[] = { 0, -1, 0, 1, 0, 0 };

int dist[100][100][100];

struct node 
{
	int z;
	int y;
	int x;
};

bool inRange(int z, int y, int x)
{
	if (0 <= z && z < H && 0 <= y && y < N &&
		0 <= x && x < M)
	{
		return true;
	}

	return false;
}

int calculate()
{
	int result = 0;

	for (int z = 0; z < H; z++)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (box[z][y][x] == 0 && dist[z][y][x] == 0)
				{
					return -1;
				}

				result = max(result, dist[z][y][x]);
			}
		}
	}

	return result - 1;
}

int bfs(vector<node> reap)
{
	queue<node> q;
	
	for (node init : reap)
	{
		dist[init.z][init.y][init.x] = 1;
		q.push(init);
	}

	while (!q.empty())
	{
		node present = q.front();
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nz = present.z + dz[i];
			int ny = present.y + dy[i];
			int nx = present.x + dx[i];

			if (inRange(nz, ny, nx) && dist[nz][ny][nx] == 0 && box[nz][ny][nx] != -1)
			{
				dist[nz][ny][nx] = dist[present.z][present.y][present.x] + 1;

				q.push({ nz, ny, nx });
			}
		}
	}

	return calculate();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H;

	int notReap = 0;
	vector<node> reap;

	for (int z = 0; z < H; z++)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				cin >> box[z][y][x];

				if (box[z][y][x] == 1)
				{
					reap.push_back({ z, y, x });
				}
				else if (box[z][y][x] == 0)
				{
					notReap++;
				}
			}
		}
	}

	if (notReap == 0)
	{
		cout << 0 << '\n';

		return 0;
	}
	
	int answer = bfs(reap);

	cout << answer << '\n';

	return 0;
}