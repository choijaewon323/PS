#include <iostream>
using namespace std;

int main()
{
	int x[1001] = { 0 };
	int y[1001] = { 0 };
	int a, b;
	
	for (int i = 0; i < 3; i++)
	{
		cin >> a >> b;
		x[a]++;
		y[b]++;
	}

	int X, Y;

	for (int i = 0; i <= 1000; i++)
	{
		if (x[i] == 1)
		{
			X = i;
		}
		if (y[i] == 1)
		{
			Y = i;
		}
	}

	cout << X << " " << Y << '\n';

	return 0;
}