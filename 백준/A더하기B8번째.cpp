#include <iostream>
using namespace std;

int main()
{
	int test;
	cin >> test;

	for (int i = 0; i < test; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << "Case #" << i + 1 << ": " << a << " + " << b << " = " << a + b << '\n';
	}

	return 0;
}