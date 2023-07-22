#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// dice index
#define BELOW 0
#define SOUTH 1
#define UP 2
#define NORTH 3
#define WEST 4
#define EAST 5

// dice direction
#define MEAST 0
#define MSOUTH 1
#define MWEST 2
#define MNORTH 3

vector<int> dice = { 6, 5, 1, 2, 4, 3 };

void moveDice(int direction)
{
	vector<int> result(6, 0);

	switch (direction)
	{
	case MEAST:
		result[WEST] = dice[BELOW];
		result[SOUTH] = dice[SOUTH];
		result[EAST] = dice[UP];
		result[NORTH] = dice[NORTH];
		result[UP] = dice[WEST];
		result[BELOW] = dice[EAST];
		break;

	case MSOUTH:
		result[BELOW] = dice[SOUTH];
		result[SOUTH] = dice[UP];
		result[UP] = dice[NORTH];
		result[NORTH] = dice[BELOW];
		result[WEST] = dice[WEST];
		result[EAST] = dice[EAST];

		break;

	case MWEST:
		result[BELOW] = dice[WEST];
		result[SOUTH] = dice[SOUTH];
		result[UP] = dice[EAST];
		result[NORTH] = dice[NORTH];
		result[WEST] = dice[UP];
		result[EAST] = dice[BELOW];
		break;

	case MNORTH:
		result[BELOW] = dice[NORTH];
		result[SOUTH] = dice[BELOW];
		result[UP] = dice[SOUTH];
		result[NORTH] = dice[UP];
		result[WEST] = dice[WEST];
		result[EAST] = dice[EAST];
		break;
	}

	dice = result;
}

int opposite(int direction)
{
	switch (direction)
	{
	case MEAST:
		return MWEST;
	case MSOUTH:
		return MNORTH;
	case MWEST:
		return MEAST;
	case MNORTH:
		return MSOUTH;
	}
}

int N, M, K;
int matrix[21][21];

bool inRange(int y, int x)
{
	if (1 <= y && y <= N && 1 <= x && x <= M)
	{
		return true;
	}
	return false;
}

pair<int, int> nextPosition(int y, int x, int direction)
{
	int nextY = y, nextX = x;

	switch (direction)
	{
	case MEAST:
		nextX++;
		break;
	case MSOUTH:
		nextY++;
		break;
	case MWEST:
		nextX--;
		break;
	case MNORTH:
		nextY--;
		break;
	}

	return { nextY, nextX };
}

int cnt = 0;

vector<vector<bool>> visited;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void dfs(int startY, int startX, int num)
{
	visited[startY][startX] = true;

	cnt++;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = startY + dy[i];
		int nx = startX + dx[i];

		if (inRange(ny, nx) && !visited[ny][nx] && matrix[ny][nx] == num)
		{
			dfs(ny, nx, num);
		}
	}
}

int rollClock(int direction)
{
	switch (direction)
	{
	case MEAST:
		return MSOUTH;
	case MSOUTH:
		return MWEST;
	case MWEST:
		return MNORTH;
	case MNORTH:
		return MEAST;
	}
}

int rollCounter(int direction)
{
	switch (direction)
	{
	case MEAST:
		return MNORTH;
	case MSOUTH:
		return MEAST;
	case MWEST:
		return MSOUTH;
	case MNORTH:
		return MWEST;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= M; x++)
		{
			cin >> matrix[y][x];
		}
	}

	// init
	int direction = MEAST;
	int answer = 0;
	int y = 1, x = 1;

	for (int i = 0; i < K; i++)
	{
		// 1
		pair<int, int> next = nextPosition(y, x, direction);
		if (!inRange(next.first, next.second))
		{
			direction = opposite(direction);
			next = nextPosition(y, x, direction);
			y = next.first;
			x = next.second;
			moveDice(direction);
		}
		else
		{
			y = next.first;
			x = next.second;
			moveDice(direction);
		}
		

		// 2
		cnt = 0;
		visited = vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));
		dfs(y, x, matrix[y][x]);
		answer += cnt * matrix[y][x];

		// 3
		int below = dice[BELOW];
		if (below > matrix[y][x])
		{
			direction = rollClock(direction);
		}
		else if (below < matrix[y][x])
		{
			direction = rollCounter(direction);
		}
	}

	cout << answer << '\n';

	return 0;
}