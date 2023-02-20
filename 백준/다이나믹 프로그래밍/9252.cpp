#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string input1, input2;
int dp[1000][1000];

int func(int index1, int index2)
{
	if (index1 == input1.size() || index2 == input2.size())
	{
		return 0;
	}

	if (dp[index1][index2] != -1)
	{
		return dp[index1][index2];
	}

	if (input1[index1] == input2[index2])
	{
		return dp[index1][index2] = func(index1 + 1, index2 + 1) + 1;
	}
	else
	{
		int result = max(func(index1 + 1, index2), func(index1, index2 + 1));

		return dp[index1][index2] = result;
	}
}

void print(int index1, int index2)
{
	if (index1 == input1.size() || index2 == input2.size())
	{
		return;
	}

	if (input1[index1] == input2[index2])
	{
		cout << input1[index1];
		print(index1 + 1, index2 + 1);
	}
	else
	{
		int res1 = func(index1 + 1, index2);
		int res2 = func(index1, index2 + 1);

		if (res1 > res2)
		{
			print(index1 + 1, index2);
		}
		else
		{
			print(index1, index2 + 1);
		}
	}
}

void input()
{
	cin >> input1;
	cin >> input2;

	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			dp[i][j] = -1;
		}
	}
}

void solution()
{
	cout << func(0, 0) << '\n';
	print(0, 0);
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();

	return 0;
}