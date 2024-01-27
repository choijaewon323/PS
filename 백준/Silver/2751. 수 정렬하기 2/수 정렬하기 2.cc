#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

vector<int> numbers;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}

	sort(numbers.begin(), numbers.end());

	for (int num : numbers)
	{
		cout << num << '\n';
	}

	return 0;
}