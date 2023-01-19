#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int test_case;
	int testNum;

	for (test_case = 1; test_case <= 10; test_case++)
	{
		queue<int> q;
		int temp;

		cin >> testNum;

		for (int i = 0; i < 8; i++)
		{
			cin >> temp;
			q.push(temp);
		}

		temp = 0;
		while (true)
		{
			int num;
			temp = temp % 5 + 1;
			num = q.front();
			q.pop();
			num = num - temp;
			if (num <= 0)
			{
				num = 0;
				q.push(num);
				break;
			}
			else
			{
				q.push(num);
			}
		}

		cout << "#" << test_case << " ";
		while (!q.empty())
		{
			int num = q.front();
			q.pop();
			cout << num << " ";
		}
		cout << '\n';
	}

	return 0;
}