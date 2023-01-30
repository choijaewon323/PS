#include <iostream>
using namespace std;

int volume[50];
int memo[50][1001];
int n, m;

int solution(int index, int presentVol)
{
	if (index == n)
	{
		return presentVol;
	}

	if (memo[index][presentVol] != -2)
	{
		return memo[index][presentVol];
	}

	int result1, result2;

	result1 = -1;
	if (presentVol + volume[index] <= m)
	{
		result1 = solution(index + 1, presentVol + volume[index]);
	}

	result2 = -1;
	if (presentVol - volume[index] >= 0)
	{
		result2 = solution(index + 1, presentVol - volume[index]);
	}

	return memo[index][presentVol] = max(result1, result2);
}

int main()
{
	int s;

	cin >> n >> s >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> volume[i];
	}

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 1001; j++)
		{
			memo[i][j] = -2;
		}
	}

	cout << solution(0, s) << '\n';

	return 0;
}