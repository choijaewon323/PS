#include <iostream>
using namespace std;

int main()
{
	int a, b, ra = 0, rb = 0;

	cin >> a >> b;

	ra += a % 10 * 100;
	rb += b % 10 * 100;

	a /= 10;
	b /= 10;

	ra += a % 10 * 10;
	rb += b % 10 * 10;

	ra += a / 10;
	rb += b / 10;

	if(ra > rb)
	{
		cout << ra << endl;
	}
	else
	{
		cout << rb << endl;
	}

	return 0;
}