#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d;
int visited[1000001];

int bfs()
{
	queue<int> q;

	visited[s] = 1;
	q.push(s);

	while (!q.empty())
	{
		int temp = q.front();
		int up, down;
		q.pop();

		if (temp == g)
		{
			return visited[temp];
		}

		up = temp + u;
		if (up >= 1 && up <= f && visited[up] == 0)
		{
			visited[up] = visited[temp] + 1;
			q.push(up);
		}

		down = temp - d;
		if (down >= 1 && down <= f && visited[down] == 0)
		{
			visited[down] = visited[temp] + 1;
			q.push(down);
		}
	}

	return 0;
}

int main()
{
	int result;
	
	cin >> f >> s >> g >> u >> d;
	result = bfs();

	if (result == 0)
	{
		cout << "use the stairs" << '\n';
	}
	else
	{
		cout << result - 1 << '\n';
	}

	return 0;
}