#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;

	cin >> t;

	for (int test = 0; test < t; test++)
	{
		priority_queue<int, vector<int>, greater<int>> minPQ;
		priority_queue<int> maxPQ;
		map<int, int> m;
		int k;

		cin >> k;

		for (int com = 0; com < k; com++)
		{
			char c;
			int n;

			cin >> c >> n;

			if (c == 'I')
			{
				minPQ.push(n);
				maxPQ.push(n);
				m[n]++;
			}
			else if (c == 'D')
			{
				if (maxPQ.empty())
				{
					continue;
				}
				if (n == 1)
				{
					while (!maxPQ.empty() && m[maxPQ.top()] == 0)
					{
						maxPQ.pop();
					}
					// 최댓값 삭제
					int temp = maxPQ.top();
					maxPQ.pop();
					m[temp]--;
				}
				else if (n == -1)
				{
					while (!minPQ.empty() && m[minPQ.top()] == 0)
					{
						minPQ.pop();
					}
					// 최솟값 삭제
					int temp = minPQ.top();
					minPQ.pop();
					m[temp]--;
				}
			}

			while (!maxPQ.empty() && m[maxPQ.top()] == 0)
			{
				maxPQ.pop();
			}
			while (!minPQ.empty() && m[minPQ.top()] == 0)
			{
				minPQ.pop();
			}
		}

		if (maxPQ.empty())
		{
			cout << "EMPTY" << '\n';
		}
		else
		{
			cout << maxPQ.top() << " " << minPQ.top() << '\n';
		}
	}

	return 0;
}