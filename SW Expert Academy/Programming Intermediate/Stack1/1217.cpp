#include <iostream>

using namespace std;

int func(int n, int m)
{
	if (m == 1)
	{
		return n;
	}
	return n * func(n, m - 1);
}

int main(int argc, char **argv)
{
	int test_case;
	int testNum;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int n, m;

		cin >> testNum;
		cin >> n >> m;

		cout << "#" << test_case << " " << func(n, m) << '\n';
	}
	return 0;
}