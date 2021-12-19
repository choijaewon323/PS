#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x != 0)
		{
			if (x < 0)
			{
				q.push(make_pair(-x, x));
			}
			else
			{
				q.push(make_pair(x, x));
			}
		}
		else
		{
			if (q.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << q.top().second << '\n';
				q.pop();
			}
		}
	}
	return 0;
}