#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int n;
int arr[100002];
int result;

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
}

void solution()
{
	stack<int> st;

	st.push(0);
	for (int i = 1; i <= n + 1; i++)
	{
		while (!st.empty() && arr[st.top()] > arr[i])
		{
			int temp = st.top();
			st.pop();

			result = max(result, arr[temp] * (i - 1 - st.top()));
		}
		st.push(i);
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