#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

#define R 31
#define M 1234567891

int64_t power(int a, int n)
{
	if (n == 0)
	{
		return 1;
	}

	return a * power(a, n - 1) % M;
}

int main()
{
	string input;
	int l;
	int64_t result = 0;

	cin >> l;
	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		int num = input[i] - 'a' + 1;
		result += num * power(R, i) % M;
		result %= M;
	}

	cout << result << '\n';

	return 0;
}