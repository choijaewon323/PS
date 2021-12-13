#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int n;
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
	if (data < arr[index])
	{
		return dp[index][data] = max(func(index + 1, data), arr[index] + func(index + 1, arr[index]));
	}
	return dp[index][data] = func(index + 1, data);
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