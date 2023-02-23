#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

bool visited[1000001];

vector<int> bfs(int start)
{
	queue<pair<int, vector<int>>> q;

	visited[start] = true;
	q.push(make_pair(start, vector<int>(1, start)));

	while (!q.empty())
	{
		int present = q.front().first;
		vector<int> cnt = q.front().second;
		q.pop();

		if (present == 1)
		{
			return cnt;
		}

		if (present % 3 == 0 && !visited[present / 3])
		{
			visited[present / 3] = true;
			vector<int> temp = cnt;
			temp.push_back(present / 3);
			q.push(make_pair(present / 3, temp));
		}
		if (present % 2 == 0 && !visited[present / 2])
		{
			visited[present / 2] = true;
			vector<int> temp = cnt;
			temp.push_back(present / 2);
			q.push(make_pair(present / 2, temp));
		}
		if (!visited[present - 1])
		{
			visited[present - 1] = true;
			vector<int> temp = cnt;
			temp.push_back(present - 1);
			q.push(make_pair(present - 1, temp));
		}
	}
}

void input()
{
	int n;
	cin >> n;

	vector<int> result = bfs(n);

	cout << result.size() - 1 << '\n';
	
	for (auto r : result)
	{
		cout << r << " ";
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);

	input();

	return 0;
}