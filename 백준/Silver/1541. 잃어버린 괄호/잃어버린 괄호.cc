#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000000000
#define MAX 100
#define MAX_FLAG 0
#define MIN_FLAG 1

vector<int> numbers;
vector<char> operators;
int dp[MAX][MAX][2];

bool isNumber(char c)
{
	if ('0' <= c && c <= '9')
	{
		return true;
	}
	return false;
}

void split(string expression)
{
	string number = "";
	for (char e : expression)
	{
		if (isNumber(e))
		{
			number += e;
		}
		else
		{
			numbers.push_back(stoi(number));
			number = "";
			operators.push_back(e);
		}
	}
	numbers.push_back(stoi(number));
}

int solve(int start, int end, int flag)
{
	if (start == end)
	{
		return numbers[start];
	}
	if (dp[start][end][flag] != INF)
	{
		return dp[start][end][flag];
	}
	int result;
	if (flag == MAX_FLAG)
	{
		result = -INF;
	}
	else
	{
		result = INF;
	}
	for (int i = start; i <= end - 1; i++)
	{
		if (operators[i] == '+')
		{
			if (flag == MAX_FLAG)
			{
				result = max(result, solve(start, i, MAX_FLAG) + solve(i + 1, end, MAX_FLAG));
			}
			else
			{
				result = min(result, solve(start, i, MIN_FLAG) + solve(i + 1, end, MIN_FLAG));
			}
		}
		else
		{
			if (flag == MAX_FLAG)
			{
				result = max(result, solve(start, i, MAX_FLAG) - solve(i + 1, end, MIN_FLAG));
			}
			else
			{
				result = min(result, solve(start, i, MIN_FLAG) - solve(i + 1, end, MAX_FLAG));
			}
		}
	}
	return dp[start][end][flag] = result;
}

void init()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				dp[i][j][k] = INF;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string expression;
	cin >> expression;
	split(expression);
	init();
	int answer = solve(0, numbers.size() - 1, MIN_FLAG);
	cout << answer << '\n';
	return 0;
}