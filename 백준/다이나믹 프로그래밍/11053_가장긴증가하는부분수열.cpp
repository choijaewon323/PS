#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[1001];
int dp[1001][1001];
int func(int index, int data)
{
	if (index > n)
	{
		return 0;
	}
	if (dp[index][data] != 0)
	{
		return dp[index][data];
	}
	if (arr[index] > data)
	{
		return dp[index][data] = max(func(index + 1, arr[index]) + 1, func(index + 1, data));
	}
	return func(index + 1, data);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	cout << func(0, 0) << '\n';
	return 0;
}