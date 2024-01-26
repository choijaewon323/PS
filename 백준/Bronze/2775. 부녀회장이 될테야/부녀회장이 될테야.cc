#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 14

int apartment[MAX + 1][MAX + 1];

int calculate(const int y, const int x)
{
	int result = 0;

	for (int i = 1; i <= x; i++)
	{
		result += apartment[y - 1][i];
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int x = 1; x <= 14; x++)
	{
		apartment[0][x] = x;
	}

	for (int y = 1; y <= 14; y++)
	{
		for (int x = 1; x <= 14; x++)
		{
			apartment[y][x] = calculate(y, x);
		}
	}

	int T;
	cin >> T;

	for (int test = 0; test < T; test++)
	{
		int k, n;
		cin >> k >> n;

		cout << apartment[k][n] << '\n';
	}
	
	return 0;
}