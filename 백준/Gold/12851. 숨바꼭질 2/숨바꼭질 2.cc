#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, answer = -1, cnt;
bool visited[100001];

bool inRange(int x)
{
	if (0 <= x && x <= 100000)
	{
		return true;
	}
	return false;
}
int bfs()
{
	queue<pair<int, int>> q;

	visited[n] = true;
	q.push({ n, 0 });

	while (!q.empty())
	{
		int x = q.front().first;
		int sec = q.front().second;
		int next;
		q.pop();

		visited[x] = true;

		if (x == k && answer != -1)	// later visit
		{
			if (sec == answer)
			{
				cnt++;
			}
		}

		if (x == k && answer == -1)	// first visit
		{
			answer = sec;
			cnt++;
		}

		next = x + 1;
		if (inRange(next) && !visited[next])
		{
			q.push({ next, sec + 1 });
		}

		next = x - 1;
		if (inRange(next) && !visited[next])
		{
			q.push({ next, sec + 1 });
		}

		if (x != 0)
		{
			next = x * 2;
			if (inRange(next) && !visited[next])
			{
				q.push({ next, sec + 1 });
			}
		}
	}

	return answer;
}

int main()
{
	cin >> n >> k;

	bfs();

	cout << answer << '\n';
	cout << cnt << '\n';

	return 0;
}