#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
	int c;

	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	vector<int> numbers;
	vector<int> answers;
	vector<int> results;
	vector<int> sub;
	int n;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}

	sort(numbers.begin(), numbers.end());

	for (int i = 1; i < numbers.size(); i++)
	{
		sub.push_back(numbers[i] - numbers[i - 1]);
	}

	for (int i = 1; i < sub.size(); i++)
	{
		int temp;
		temp = gcd(sub[i], sub[i - 1]);
		sub[i] = temp;
	}

	for (int i = 1; i <= sqrt(sub.back()); i++)
	{
		if (sub.back() % i == 0)
		{
			answers.push_back(i);
			results.push_back(i);
		}
	}

	for (auto i : answers)
	{
		int temp = sub.back() / i;

		if (i == temp)
		{
			continue;
		}

		results.push_back(temp);
	}

	sort(results.begin(), results.end());

	for (auto a : results)
	{
		if (a == 1)
		{
			continue;
		}

		cout << a << " ";
	}
	cout << '\n';

	return 0;
}