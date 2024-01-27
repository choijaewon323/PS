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

int N;
vector<int> numbers;
map<int, int> cnt;

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}
}

void mean()
{
	double acc = 0;

	for (int num : numbers)
	{
		acc += num;
	}

	const double temp = acc / numbers.size();
	const double result = round(temp);

	cout << result + 0.0 << '\n';
}

void middle()
{
	cout << numbers[numbers.size() / 2] << '\n';
}

bool compare(int a, int b)
{
	if (cnt[a] == cnt[b])
	{
		return a < b;
	}
	return cnt[a] > cnt[b];
}

void mode()
{
	if (numbers.size() == 1)
	{
		cout << numbers[0] << '\n';

		return;
	}

	for (int num : numbers)
	{
		cnt[num]++;
	}

	vector<int> temp;

	for (auto iter = cnt.begin(); iter != cnt.end(); iter++)
	{
		const int key = iter->first;

		temp.push_back(key);
	}

	sort(temp.begin(), temp.end(), compare);

	if (temp.size() == 1)
	{
		cout << temp[0] << '\n';
		return;
	}

	const int first = temp[0];
	const int second = temp[1];

	if (cnt[first] == cnt[second])
	{
		cout << second << '\n';
	}
	else
	{
		cout << first << '\n';
	}
}

void range()
{
	sort(numbers.begin(), numbers.end());

	const int minVal = numbers.front();
	const int maxVal = numbers.back();

	cout << maxVal - minVal << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	sort(numbers.begin(), numbers.end());

	mean();
	middle();
	mode();
	range();

	return 0;
}