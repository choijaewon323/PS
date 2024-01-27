#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

bool isValid(const string &input)
{
	stack<char> st;

	for (char c : input)
	{
		if (c == '(')
		{
			st.push(c);
		}
		else
		{
			if (st.empty())
			{
				return false;
			}
			else
			{
				if (st.top() == '(')
				{
					st.pop();
				}
				else
				{
					return false;
				}
			}
		}
	}

	if (!st.empty())
	{
		return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int test = 0; test < T; test++)
	{
		string input;
		cin >> input;

		if (isValid(input))
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}

	return 0;
}