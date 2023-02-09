#include <iostream>
#include <queue>
#include <utility>
using namespace std;

short ladOrSnake[101];
int result;
bool visited[101];

void bfs()
{
	queue<pair<int, int>> q;
	
	q.push(make_pair(1, 0));

	while (!q.empty())
	{
		pair<int, int> present = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++)
		{
			int next = present.first + i;

			if (next == 100)
			{
				result = present.second + 1;
				return;
			}
			if (next >= 1 && next < 100)
			{
				if (ladOrSnake[next] != 0)
				{
					q.push(make_pair(ladOrSnake[next], present.second + 1));
				}
				else if (!visited[next])
				{
					visited[next] = true;
					q.push(make_pair(next, present.second + 1));
				}
			}
		}
	}
}

int main()
{
	int n, m;
	short start, end;

	cin >> n >> m;

	for (int i = 0; i < n + m; i++)
	{
		cin >> start >> end;
		ladOrSnake[start] = end;
	}

	bfs();

	cout << result << '\n';

	return 0;
}