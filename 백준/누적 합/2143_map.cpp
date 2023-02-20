#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int a[1001];
int b[1001];
long long t;
int n, m;
long long result;
vector<int> subSum;
map<int, int> mp;

void makeSum(int arr[], int dist)
{
	int left = 1;
	int right = 1 + dist;
	int temp;

	while (right <= n)
	{
		temp = arr[right] - arr[left - 1];
		//subSum.push_back(temp);
		mp[temp]++;
		left++;
		right++;
	}
}

void makeSolution(int arr[], int dist)
{
	int left = 1;
	int right = 1 + dist;

	while (right <= m)
	{
		int temp = arr[right] - arr[left - 1];

		result += mp[t - temp];

		//int index = lower_bound(subSum.begin(), subSum.end(), t - temp) - subSum.begin();

		//if (index != subSum.end() - subSum.begin())
		//{
		//	while (index != subSum.size())
		//	{
		//		if (temp + subSum[index] == t)
		//		{
			//		index++;
					//result++;;
				//}
			//	else
				//{
					//break;
				//}
		//	}
		//}

		left++;
		right++;
	}
}

void input()
{
	cin >> t;
	cin >> n;

	int acc = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];

		acc += a[i];
		a[i] = acc;
	}

	cin >> m;

	acc = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];

		acc += b[i];
		b[i] = acc;
	}
}

void solution()
{
	// a 배열 모든 부배열합 구하기
	for (int i = 0; i <= n - 1; i++)
	{
		makeSum(a, i);
	}

	//sort(subSum.begin(), subSum.end());

	for (int i = 0; i <= m - 1; i++)
	{
		makeSolution(b, i);
	}

	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();

	return 0;
}