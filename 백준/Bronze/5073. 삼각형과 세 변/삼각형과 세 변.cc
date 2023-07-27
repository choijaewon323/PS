#include <iostream>
#include <algorithm>

using namespace std;

bool isValid(int a, int b, int c)
{
	int maxNum = max(a, max(b, c));

	int sum = a + b + c;
	

	if (sum - maxNum <= maxNum)
	{
		return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;

	while (true)
	{
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}

		if (!isValid(a, b, c))
		{
			cout << "Invalid" << '\n';
			continue;
		}

		if (a == b && b == c && a == c)
		{
			cout << "Equilateral" << '\n';
			continue;
		}

		if ((a == b && b != c) || (b == c && c != a) || (a == c && c != b))
		{
			cout << "Isosceles" << '\n';
			continue;
		}

		if ((a != b && b != c && c != a))
		{
			cout << "Scalene" << '\n';
		}
	}

	return 0;
}