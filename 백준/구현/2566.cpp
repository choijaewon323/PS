#include <iostream>
using namespace std;

int main()
{
	int result = -1;
	int i, j;
	int temp;

	for (int y = 1; y <= 9; y++)
	{
		for (int x = 1; x <= 9; x++)
		{
			cin >> temp;

			if (temp > result)
			{
				result = temp;
				i = y;
				j = x;
			}
		}
	}

	cout << result << '\n';
	cout << i << " " << j << '\n';

	return 0;
}