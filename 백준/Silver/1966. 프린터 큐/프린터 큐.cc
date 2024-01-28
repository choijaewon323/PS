#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#include <cmath>

using namespace std;

#define MAX 9

int priority[MAX + 1];

bool isUpperPresent(const int pri)
{
	for (int i = 9; i > pri; i--)
	{
		if (priority[i] > 0)
		{
			return true;
		}
	}

	return false;
}

int solve(queue<pair<int, int>> &q, const int toFind)
{
	int answer = 1;
	while (!q.empty())
	{
		const int idx = q.front().first;
		const int pri = q.front().second;

		if (isUpperPresent(pri))
		{
			q.pop();
			q.push({ idx, pri });
		}
		else
		{
			if (idx == toFind)
			{
				return answer;
			}
			else
			{
				q.pop();
				priority[pri]--;
				answer++;
			}
		}
	}

	return -1;
}

void init()
{
	for (int i = 0; i < MAX + 1; i++)
	{
		priority[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		int N, M;
		cin >> N >> M;
		
		init();
		queue<pair<int, int>> q;
		for (int i = 0; i < N; i++)
		{
			int pri;
			cin >> pri;
			q.push({ i, pri });
			priority[pri]++;
		}

		cout << solve(q, M) << '\n';
	}

	return 0;
}