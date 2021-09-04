#include <iostream>
using namespace std;

int main()
{
	bool* eratos = new bool[1000001];

	for (int i = 0; i < 1000001; i++)
	{
		eratos[i] = true;
	}

	eratos[0] = false;
	eratos[1] = false;

	for (int i = 2; i * i <= 1000000; i++)
	{
		if (eratos[i])
		{
			int n = 2;

			for (; i * n <= 1000000; n++)
			{
				eratos[i * n] = false;
			}
		}
	}

	int m, n;
	cin >> m >> n;

	for (int i = m; i <= n; i++)
	{
		if (eratos[i])
		{
			cout << i << '\n';
		}
	}

	return 0;
}