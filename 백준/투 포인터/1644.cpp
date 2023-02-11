#include <iostream>
#include <vector>
using namespace std;

#define MAX 4000000

vector<int> primes;
int n;
bool isPrime[MAX + 1];

void eratos()
{
	for (int i = 2; i <= MAX; i++)
	{
		isPrime[i] = true;
	}

	for (int i = 2; i * i <= MAX; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= MAX; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	for (int i = 2; i <= MAX; i++)
	{
		if (isPrime[i])
		{
			primes.push_back(i);
		}
	}
}

int func()
{
	int left, right, sum;
	int result = 0;

	left = 0, right = 0; sum = primes[0];
	while (1)
	{
		if (right == primes.size() - 1)
		{
			for (int i = left; i <= right; i++)
			{
				sum -= primes[left];
				if (sum == n)
				{
					result++;
				}
			}
			break;
		}

		if (left == right)
		{
			if (sum == n)
			{
				result++;
			}
			sum += primes[++right];
			continue;
		}

		if (sum == n)
		{
			result++;
			sum += primes[++right];
		}
		else if (sum > n)
		{
			sum -= primes[left++];
		}
		else
		{
			sum += primes[++right];
		}
	}

	return result;
}

int main()
{
	cin >> n;

	if (n == 1)
	{
		cout << 0 << '\n';
		return 0;
	}

	eratos();

	cout << func() << '\n';

	return 0;
}