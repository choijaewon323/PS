#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000

bool isNotPrime[MAX + 1];

void eratos()
{
	for (int i = 3; i * i <= MAX; i += 2)
	{
		if (!isNotPrime[i])
		{
			for (int j = i * i; j <= MAX; j += i)
			{
				isNotPrime[j] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	eratos();
	int t;

	while (1)
	{
		int n;
		bool answered = false;
		
		cin >> n;
		
		if (n == 0)
		{
			break;
		}

		for (int i = 3; i <= MAX; i += 2)
		{
			if (isNotPrime[i])
			{
				continue;
			}
			if (n - i <= 2)
			{
				break;
			}
			if (!isNotPrime[n - i])
			{
				cout << n << " = " << i << " + " << n - i << '\n';
				answered = true;
				break;
			}
		}

		if (!answered)
		{
			cout << "Goldbach\'s conjecture is wrong." << '\n';
		}
	}

	return 0;
}