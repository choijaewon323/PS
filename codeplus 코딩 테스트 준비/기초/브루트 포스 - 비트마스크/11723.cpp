#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string command;
	int numSet = 0;
	int m, x;
	
	cin >> m;
	cin.ignore();

	for (int com = 0; com < m; com++)
	{
		cin >> command;

		if (command == "add")
		{
			cin >> x;

			numSet |= (1 << x);
		}
		else if (command == "remove")
		{
			cin >> x;

			numSet &= ~(1 << x);
		}
		else if (command == "check")
		{
			cin >> x;

			if (numSet & (1 << x))
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (command == "toggle")
		{
			cin >> x;

			numSet ^= (1 << x);
		}
		else if (command == "all")
		{
			for (int i = 1; i <= 20; i++)
			{
				numSet |= (1 << i);
			}
		}
		else if (command == "empty")
		{
			numSet = 0;
		}
	}

	return 0;
}