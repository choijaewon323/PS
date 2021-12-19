#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	priority_queue<int, vector<int>, greater<int>> q;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x)
		{
			q.push(x);
		}
		else
		{
			if (q.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << q.top() << '\n';
				q.pop();
			}
		}
	}
	return 0;
}