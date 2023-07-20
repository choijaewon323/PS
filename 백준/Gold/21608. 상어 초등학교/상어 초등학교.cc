#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int matrix[21][21];
vector<int> inputs;
vector<int> friends[401];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

typedef struct _node
{
	int y;
	int x;
	int empty;
	int friends;
} node;

bool compare(node &a, node &b)
{
	if (a.friends == b.friends && a.empty == b.empty && a.y == b.y)
	{
		return a.x < b.x;
	}
	else if (a.friends == b.friends && a.empty == b.empty)
	{
		return a.y < b.y;
	}
	else if (a.friends == b.friends)
	{
		return a.empty > b.empty;
	}

	return a.friends > b.friends;
}

void input()
{
	cin >> n;

	for (int i = 1; i <= n * n; i++)
	{
		int me, a, b, c, d;

		cin >> me >> a >> b >> c >> d;

		inputs.push_back(me);

		friends[me].push_back(a);
		friends[me].push_back(b);
		friends[me].push_back(c);
		friends[me].push_back(d);
	}
}

bool inRange(int y, int x)
{
	if (1 <= y && y <= n && 1 <= x && x <= n)
	{
		return true;
	}

	return false;
}

bool isLike(int me, int student)
{
	if (student == 0)
	{
		return false;
	}

	for (int i = 0; i < 4; i++)
	{
		if (student == friends[me][i])
		{
			return true;
		}
	}

	return false;
}

node condition(int present)
{
	vector<node> result;

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			if (matrix[y][x] == 0)
			{
				int empty = 0;
				int friends = 0;

				// friends and empty

				for (int i = 0; i < 4; i++)
				{
					int ny = y + dy[i];
					int nx = x + dx[i];

					bool in = inRange(ny, nx);

					if (in && matrix[ny][nx] == 0)
					{
						empty++;
					}

					if (in && isLike(present, matrix[ny][nx]))
					{
						friends++;
					}
				}

				result.push_back({ y, x, empty, friends });
			}
		}
	}


	sort(result.begin(), result.end(), compare);

	return result.front();
}

int solution()
{
	int answer = 0;

	// place setting
	for (int i : inputs)
	{
		node place = condition(i);

		matrix[place.y][place.x] = i;
	}
	
	// sum
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			int me = matrix[y][x];
			int cnt = 0;

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (inRange(ny, nx) && isLike(me, matrix[ny][nx]))
				{
					cnt++;
				}
			}

			switch (cnt)
			{
			case 1:
				answer += 1;
				break;
			case 2:
				answer += 10;
				break;
			case 3:
				answer += 100;
				break;
			case 4:
				answer += 1000;
				break;

			}
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();

	cout << solution() << '\n';

	return 0;
}