#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	deque<int> dq;
	for (int commands = 0; commands < N; commands++)
	{
		string command;
		cin >> command;

		if (command == "push_front")
		{
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (command == "push_back")
		{
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (command == "pop_front")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (command == "pop_back")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (command == "size")
		{
			cout << dq.size() << '\n';
		}
		else if (command == "empty")
		{
			cout << (int)dq.empty() << '\n';
		}
		else if (command == "front")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
			}
		}
		else 
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.back() << '\n';
			}
		}
	}

	return 0;
}