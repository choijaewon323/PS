#include <iostream>
using namespace std;

int fibonacci(int idx) {
	if (idx == 0)
	{
		return 0;
	}
	if (idx == 1)
	{
		return 1;
	}

	return fibonacci(idx - 1) + fibonacci(idx - 2);
}

int main()
{
	int n;
	cin >> n;

	cout << fibonacci(n) << '\n';

	return 0;
}