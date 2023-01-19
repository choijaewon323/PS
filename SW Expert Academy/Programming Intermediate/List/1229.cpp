#include <iostream>
#include <list>
#include <stack>
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
			stack<int> st;
			cin >> command;

			if (command == 'I')
			{
				cin >> x >> y;
				for (int j = 0; j < y; j++)
				{
					cin >> s;
					st.push(s);
				}
				for (int j = 0; j < y; j++)
				{
					list<int>::iterator pos = lst.begin();
					int temp = st.top();
					st.pop();
					for (int j = 0; j < x; j++)
					{
						pos++;
					}
					lst.insert(pos, temp);
				}
			}
			else if (command == 'D')
			{
				list<int>::iterator pos = lst.begin();
				cin >> x >> y;
				for (int j = 0; j < x; j++)
				{
					pos++;
				}
				
				for (int j = 0; j < y; j++)
				{
					pos = lst.erase(pos);
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