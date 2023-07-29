#include <iostream>
#include <climits>

using namespace std;

typedef long long ll;

int main()
{
	ll X, Y;

	cin >> X >> Y;

	ll Z = Y * 100 / X;

	if (Z >= 99)
	{
		cout << -1 << '\n';
		return 0;
	}

	ll left = 0;
	ll right = 1000000000;
	ll answer = -1;
	
	while (left <= right)
	{
		ll mid = (left + right) / 2;

		ll tempX = X + mid;
		ll tempY = Y + mid;
		ll tempZ = tempY * 100 / tempX;

		if (tempZ > Z)
		{
			answer = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << answer << '\n';
	
	return 0;
}