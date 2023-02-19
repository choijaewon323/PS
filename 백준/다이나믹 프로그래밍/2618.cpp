#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> events;
vector<pair<int, int>> path1;
vector<pair<int, int>> path2;
int n, w;

int dp[1000][1000];

int func(int pol1, int pol2)
{
	if (pol1 == w || pol2 == w)
	{
		return 0;
	}

	if (dp[pol1][pol2] != 0)
	{
		return dp[pol1][pol2];
	}

	int next = max(pol1, pol2) + 1;

	int pol1Dis = abs(events[next].first - path1[pol1].first) +
		abs(events[next].second - path1[pol1].second);
	int pol2Dis = abs(events[next].first - path2[pol2].first) +
		abs(events[next].second - path2[pol2].second);

	int res1 = func(next, pol2) + pol1Dis;
	int res2 = func(pol1, next) + pol2Dis;

	return dp[pol1][pol2] = min(res1, res2);
}

void print(int pol1, int pol2)
{
	if (pol1 == w || pol2 == w)
	{
		return;
	}

	int next = max(pol1, pol2) + 1;

	int pol1Dis = abs(events[next].first - path1[pol1].first) +
		abs(events[next].second - path1[pol1].second);
	int pol2Dis = abs(events[next].first - path2[pol2].first) +
		abs(events[next].second - path2[pol2].second);

	int res1 = func(next, pol2) + pol1Dis;
	int res2 = func(pol1, next) + pol2Dis;

	if (res1 < res2)
	{
		cout << 1 << '\n';
		print(next, pol2);
	}
	else
	{
		cout << 2 << '\n';
		print(pol1, next);
	}
}

void input()
{
	cin >> n;
	cin >> w;

	path1.push_back(make_pair(1, 1));
	path2.push_back(make_pair(n, n));
	events.push_back(make_pair(0, 0));

	for (int i = 1; i <= w; i++)
	{
		int a, b;
		
		cin >> a >> b;
		events.push_back(make_pair(a, b));
		path1.push_back(make_pair(a, b));
		path2.push_back(make_pair(a, b));
	}
}

void solution()
{
	int result = func(0, 0);

	cout << result << '\n';
	print(0, 0);
}

int main()
{
	input();
	solution();

	return 0;
}