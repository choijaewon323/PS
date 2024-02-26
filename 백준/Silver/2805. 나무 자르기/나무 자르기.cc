#include <iostream>

using namespace std;

#define MAX 1000000

typedef long long ll;

int N, M;

int trees[MAX];

ll calculate(int height)
{
	ll result = 0;

	for (int i = 0; i < N; i++)
	{
		ll present = trees[i];

		if (present > height)
		{
			result += present - height;
		}
	}

	return result;
}

int binarySearch()
{
	int left = 0;
	int right = 1000000000;
	int result = -1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		ll treeSum = calculate(mid);

		if (treeSum >= M)
		{
			result = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		cin >> trees[i];
	}

	cout << binarySearch() << '\n';

	return 0;
}