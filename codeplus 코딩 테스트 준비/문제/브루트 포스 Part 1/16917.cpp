#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c, x, y;

int main()
{
	int seasoned, fried, sum;
	cin >> a >> b >> c >> x >> y;

	seasoned = 0;
	fried = 0;
	sum = 0;
	while (1)
	{
		if (seasoned >= x && fried >= y)
		{
			break;
		}

		if (seasoned < x && fried < y)
		{
			seasoned++;
			fried++;
			sum += min(a + b, 2 * c);
		}
		else if (seasoned < x && fried >= y)
		{
			if (a > 2 * c)
			{
				seasoned++;
				fried++;
				sum += 2 * c;
			}
			else
			{
				seasoned++;
				sum += a;
			}
		}
		else if (seasoned >= x && fried < y)
		{
			if (b > 2 * c)
			{
				seasoned++;
				fried++;
				sum += 2 * c;
			}
			else
			{
				fried++;
				sum += b;
			}
		}
	}
	
	cout << sum << '\n';

	return 0;
}