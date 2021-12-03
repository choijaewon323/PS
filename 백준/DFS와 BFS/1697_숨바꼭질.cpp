#include <iostream>
#include <queue>
using namespace std;

int n, k;
int location[100001];

int bfs()
{
	queue<int> q;
	
	if (n - 1 >= 0)
	{
		if (n - 1 == k)
		{
			return 1;
		}
		q.push(n - 1);
		location[n - 1] = 1;
	}
	if (n + 1 <= 100000)
	{
		if (n + 1 == k)
		{
			return 1;
		}
		q.push(n + 1);
		location[n + 1] = 1;
	}
	if (n * 2 != 0 && n * 2 <= 100000)
	{
		if (n * 2 == k)
		{
			return 1;
		}
		q.push(n * 2);
		location[n * 2] = 1;
	}

	int result;
	while (true)
	{
		int temp = q.front();
		int next;
		q.pop();

		next = temp - 1;
		if (next >= 0)
		{
			if (next == k)
			{
				result = location[temp] + 1;
				return result;
			}
			if (location[next] == 0)
			{
				q.push(next);
				location[next] = location[temp] + 1;
			}
		}
		next = temp + 1;
		if (next <= 100000)
		{
			if (next == k)
			{
				result = location[temp] + 1;
				return result;
			}
			if (location[next] == 0)
			{
				q.push(next);
				location[next] = location[temp] + 1;
			}
		}
		next = temp * 2;
		if (next != 0 && next <= 100000)
		{
			if (next == k)
			{
				result = location[temp] + 1;
				return result;
			}
			if (location[next] == 0)
			{
				q.push(next);
				location[next] = location[temp] + 1;
			}
		}
	}
	return result;
}

int main()
{
	cin >> n >> k;

	if (n == k)
	{
		cout << 0 << '\n';
		return 0;
	}

	cout << bfs() << '\n';

	return 0;
}