#include <iostream>
#include <vector>

using namespace std;

bool record(vector<int> &arr, int M, int mid)
{
	vector<bool> temp(arr.size(), false);

	int idx = 0;
	for (int i = 0; i < M; i++)
	{
		int tempMid = mid;
		for (; idx < arr.size(); idx++)
		{
			tempMid -= arr[idx];
			if (tempMid < 0)
			{
				break;
			}
			else
			{
				temp[idx] = true;
			}
		}
	}

	return temp.back();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	vector<int> arr;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	int left = 0;
	int right = 1000000000;
	int answer;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (record(arr, M, mid))
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