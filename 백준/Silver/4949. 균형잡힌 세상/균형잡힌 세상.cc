#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#include <cmath>

using namespace std;

bool isBlanket(const char c)
{
	switch (c)
	{
	case '(':
		return true;
	case ')':
		return true;
	case '[':
		return true;
	case ']':
		return true;
	case '{':
		return true;
	case '}':
		return true;
	}
	return false;
}

bool solve(const string &input)
{
	stack<char> st;
	for (char c : input)
	{
		if (!isBlanket(c))
		{
			continue;
		}

		if (c == '(' || c == '[' || c == '{')
		{
			st.push(c);
		}
		else if (c == ')')
		{
			if (st.empty())
			{
				return false;
			}

			if (st.top() == '(')
			{
				st.pop();
			}
			else
			{
				return false;
			}
		}
		else if (c == '}')
		{
			if (st.empty())
			{
				return false;
			}

			if (st.top() == '{')
			{
				st.pop();
			}
			else
			{
				return false;
			}
		}
		else if (c == ']')
		{
			if (st.empty())
			{
				return false;
			}

			if (st.top() == '[')
			{
				st.pop();
			}
			else
			{
				return false;
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

	while (true)
	{
		string input;
		getline(cin, input);
		
		if (input == ".")
		{
			break;
		}

		if (solve(input))
		{
			cout << "yes" << '\n';
		}
		else
		{
			cout << "no" << '\n';
		}
	}

	return 0;
}