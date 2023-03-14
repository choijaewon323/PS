#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> numbers;
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int temp;

		cin >> temp;
		numbers.push_back(temp);
	}

	sort(numbers.begin(), numbers.end());

	cout << numbers[k - 1] << '\n';
	
	return 0;
}