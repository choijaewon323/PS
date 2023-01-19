#include <iostream>
#include <list>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	int test_case;

	for (test_case = 1; test_case <= 10; test_case++)
	{
		list<int> lst;
		int n;

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			lst.push_back(temp);
		}

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			char command;
			int x, y, s;
			cin >> command;

			if (command == 'I')
			{
				vector<int> ins;
				cin >> x >> y;
				for (int j = 0; j < y; j++)
				{
					cin >> s;
					ins.push_back(s);
				}

				list<int>::iterator pos = lst.begin();
				advance(pos, x);
				lst.insert(pos, ins.begin(), ins.end());
			}
			else if (command == 'D')
			{
				list<int>::iterator pos = lst.begin();
				cin >> x >> y;
				advance(pos, x);

				for (int j = 0; j < y; j++)
				{
					pos = lst.erase(pos);
				}
			}
			else if (command == 'A')
			{
				cin >> y;

				for (int j = 0; j < y; j++)
				{
					cin >> s;
					lst.push_back(s);
				}
			}
		}


		cout << "#" << test_case << " ";

		list<int>::iterator pos = lst.begin();
		for (int i = 0; i < 10; i++)
		{
			cout << *pos << " ";
			pos++;
		}
	}

	return 0;
}