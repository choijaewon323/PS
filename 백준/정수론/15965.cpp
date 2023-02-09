#include <iostream>
#include <vector>
using namespace std;

#define MAX 10000000

bool isNotPrime[MAX + 1];
vector<int> primes;

int main()
{
	int k;

	cin >> k;

	primes.push_back(0);

	for (int i = 2; i * i <= MAX; i++)
	{
		if (!isNotPrime[i])
		{
			for (int j = i * i; j <= MAX; j += i)
			{
				isNotPrime[j] = true;
			}
		}
	}

	for (int i = 2; i <= MAX; i++)
	{
		if (!isNotPrime[i])
		{
			primes.push_back(i);
		}
	}

	cout << primes[k] << '\n';

	return 0;
}