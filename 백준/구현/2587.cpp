#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> input;
	int acc = 0;

	for (int i = 0; i < 5; i++)
	{
		int temp;

		cin >> temp;
		acc += temp;
		input.push_back(temp);
	}
	sort(input.begin(), input.end());

	cout << acc / 5 << '\n';
	cout << input[2] << '\n';

	return 0;
}