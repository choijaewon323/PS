#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<string> arr;
	string input;

	cin >> input;

	int n = input.size();


	for (int i = 0; i < n; i++)
	{
		arr.push_back(input.substr(i, n - i));
	}

	sort(arr.begin(), arr.end());

	for (auto a : arr)
	{
		cout << a << '\n';
	}

	return 0;
}