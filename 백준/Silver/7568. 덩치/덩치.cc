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

#define MAX 50

int N;

pair<int, int> people[MAX];
int answer[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		people[i] = { x, y };
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
			{
				continue;
			}

			const pair<int, int> me = people[i];
			const pair<int, int> other = people[j];

			if (me.first < other.first && me.second < other.second)
			{
				answer[i]++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << answer[i] + 1 << " ";
	}
	cout << '\n';

	return 0;
}