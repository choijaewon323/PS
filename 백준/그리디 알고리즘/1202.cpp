#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
	if (a.first == b.first)
	{
		return a.second > b.second;
	}
	return a.first < b.first;
}

#define MAX 300000

int n, k;
pair<int, int> jewel[MAX + 1];
bool isPacked[MAX + 1];
vector<int> bag;

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int m, v;

		cin >> m >> v;
		jewel[i].first = m;
		jewel[i].second = v;
	}

	for (int i = 0; i < k; i++)
	{
		int c;

		cin >> c;
		bag.push_back(c);
	}
}

void solution()
{
	sort(bag.begin(), bag.end());
	sort(jewel, jewel + n, compare);

	long long result = 0;

	int index = 0;
	
	priority_queue<int> pq;

	for (auto b : bag)
	{
		for (int i = index; i < n; i++)
		{
			if (jewel[i].first <= b)
			{
				pq.push(jewel[i].second);
				index++;
			}
			else
			{
				break;
			}
		}

		if (!pq.empty())
		{
			result += pq.top();
			pq.pop();
		}
	}

	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();

	return 0;
}