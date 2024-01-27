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

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<pair<int, int>> numbers;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;

		numbers.push_back({ x, y });
	}

	sort(numbers.begin(), numbers.end(), compare);

	for (pair<int, int> &num : numbers)
	{
		cout << num.first << " " << num.second << '\n';
	}

	return 0;
}