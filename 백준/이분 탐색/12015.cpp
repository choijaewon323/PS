#include <iostream>
#include <vector>
using namespace std;

int arr[1000001];
vector<int> subSeq;

void binary_search(int num)
{
	int low, high, mid, result;
	high = subSeq.size() - 1;
	low = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (subSeq[mid] >= num)
		{
			result = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	subSeq[result] = num;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	subSeq.push_back(arr[1]);

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] > subSeq.back())
		{
			subSeq.push_back(arr[i]);
		}
		else
		{
			binary_search(arr[i]);
		}
	}

	cout << subSeq.size() << '\n';

	return 0;
}