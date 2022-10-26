#include <iostream>
using namespace std;

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;

	if (b >= c)
	{	
		cout << -1 << '\n';
		
		return 0;
	}
	
	long long n = (a / (c - b)) + 1;

	cout << n << '\n';

	return 0;
}