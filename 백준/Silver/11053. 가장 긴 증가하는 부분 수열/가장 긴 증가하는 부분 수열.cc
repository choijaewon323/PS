#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000

int N;
int arr[MAX];
int dp[MAX];

void input() 
{
	cin >> N;

	for (int i = 0; i < N; i++) 
	{
		cin >> arr[i];
	}
}

int solve() 
{
	for (int i = 0; i < N; i++) 
	{
		const int present = arr[i];

		int temp = 0;
		for (int j = 0; j < i; j++) 
		{
			if (arr[j] < present) 
			{
				temp = max(temp, dp[j]);
			}
		}

		dp[i] = temp;
		dp[i]++;
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		answer = max(answer, dp[i]);
	}

	return answer;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	cout << solve() << '\n';

	return 0;
}