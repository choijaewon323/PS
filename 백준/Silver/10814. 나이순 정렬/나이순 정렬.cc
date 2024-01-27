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

bool compare(const pair<int, string> &a, const pair<int, string> &b)
{
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<pair<int, string>> numbers;

	for (int i = 0; i < N; i++)
	{
		int age;
		string name;
		cin >> age;
		cin.ignore();
		cin >> name;

		numbers.push_back({ age, name });
	}

	stable_sort(numbers.begin(), numbers.end(), compare);

	for (pair<int, string> &num : numbers)
	{
		cout << num.first << " " << num.second << '\n';
	}

	return 0;
}