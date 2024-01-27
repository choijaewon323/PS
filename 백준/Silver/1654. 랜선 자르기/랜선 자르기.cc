#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#include <cmath>

using namespace std;

#define MAX 10000

typedef long long ll;

ll K, N;
ll lines[MAX];

ll divide(const ll length)
{
	ll result = 0;

	for (int i = 0; i < K; i++)
	{
		const ll temp = lines[i] / length;
	
		result += temp;
	}

	return result;
}

ll binarySearch() 
{
	ll left = 1;
	ll right = INT32_MAX;
	ll result = 0;

	while (left <= right)
	{
		const ll mid = (left + right) / 2;

		if (divide(mid) >= N)
		{
			result = max(result, mid);
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

	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> lines[i];
	}

	cout << binarySearch() << '\n';

	return 0;
}