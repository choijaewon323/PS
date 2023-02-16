#include <iostream>
using namespace std;

int a[100][100];
int b[100][100];

int main()
{
	int n, m;

	cin >> n >> m;

	for (int y = 0; y <= n - 1; y++)
	{
		for (int x = 0; x <= m - 1; x++)
		{
			cin >> a[y][x];
		}
	}

	for (int y = 0; y <= n - 1; y++)
	{
		for (int x = 0; x <= m - 1; x++)
		{
			cin >> b[y][x];
			a[y][x] += b[y][x];
		}
	}

	for (int y = 0; y <= n - 1; y++)
	{
		for (int x = 0; x <= m - 1; x++)
		{
			cout << a[y][x] << " ";
		}

		cout << '\n';
	}

	return 0;
}