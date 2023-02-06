#include <iostream>
using namespace std;

long long input[1000001];
long long cnt[1001];
int n, m;

int main()
{
	long long result;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
		input[i] += input[i - 1];
		input[i] %= m;
		cnt[input[i]]++;
	}

	result = cnt[0];
	for (int i = 0; i < m; i++)
	{
		result += (cnt[i] * (cnt[i] - 1)) / 2;
	}

	cout << result << '\n';

	return 0;
}