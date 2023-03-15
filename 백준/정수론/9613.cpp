#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numbers;

int gcd(int a, int b)
{
	if (a < b)
	{
		swap(a, b);
	}

	if (b == 0)
	{
		return a;
	}

	return gcd(b, a % b);
}

int main()
{
	int t;

	cin >> t;

	for (int test = 0; test < t; test++)
	{
		int n;

		cin >> n;

		numbers = vector<int>();

		for (int i = 0; i < n; i++)
		{
			int temp;

			cin >> temp;

			numbers.push_back(temp);
		}

		int numSize = numbers.size();
		int64_t result = 0;

		sort(numbers.begin(), numbers.end());

		for (int i = 0; i < numSize - 1; i++)
		{
			for (int j = i + 1; j < numSize; j++)
			{
				result += gcd(numbers[i], numbers[j]);
			}
		}

		cout << result << '\n';
	}

	return 0;
}