#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

vector<int> numbers;
map<int, int> m;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second > b.second;
}

void input()
{
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;

		cin >> temp;
		numbers.push_back(temp);
	}
}

void solution()
{
	// 1
	int acc = 0;
	for (auto n : numbers)
	{
		acc += n;
	}
	cout << (int)round(acc / (double)numbers.size()) << '\n';

	// 2
	sort(numbers.begin(), numbers.end());

	cout << numbers[numbers.size() / 2] << '\n';

	// 3
	for (auto n : numbers)
	{
		m[n]++;
	}

	vector<pair<int, int>> vec;
	for (auto &i : m)
	{
		vec.push_back(i);
	}

	sort(vec.begin(), vec.end(), compare);

	int fir = vec.front().first;
	int sec = vec.front().second;
	int result = fir;

	for (auto i = 0; i < vec.size(); i++)
	{
		if (i == 0)
		{
			continue;
		}

		if (vec[i].second != sec)
		{
			result = fir;
			break;
		}
		else
		{
			result = vec[i].first;
			break;
		}
	}

	cout << result << '\n';

	// 4
	cout << numbers.back() - numbers.front() << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();

	return 0;
}