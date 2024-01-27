#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	stack<int> st;
	for (int commands = 0; commands < N; commands++)
	{
		string command;
		cin >> command;

		if (command == "push")
		{
			int x;
			cin >> x;
			st.push(x);
		}
		else if (command == "pop")
		{
			if (st.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (command == "size")
		{
			cout << st.size() << '\n';
		}
		else if (command == "empty")
		{
			cout << (int)st.empty() << '\n';
		}
		else
		{
			if (st.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << st.top() << '\n';
			}
		}
	}

	return 0;
}