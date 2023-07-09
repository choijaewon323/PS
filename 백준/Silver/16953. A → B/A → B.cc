#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

typedef long long ll;

ll bfs(ll start, ll end)
{
	queue<pair<ll, ll>> q;

	q.push(make_pair(start, 1));

	while (!q.empty())
	{
		pair<ll, ll> present = q.front();
		q.pop();

		if (present.first > end)
		{
			continue;
		}

		if (present.first == end)
		{
			return present.second;
		}

		// multiply 2
		q.push(make_pair(present.first * 2, present.second + 1));

		// add 1
		ll temp = present.first;
		string tempStr = to_string(temp);
		tempStr += "1";
		temp = stoll(tempStr);

		q.push(make_pair(temp, present.second + 1));
	}

	return -1;
}

int main()
{
	ll a, b;

	cin >> a >> b;

	ll result = bfs(a, b);

	cout << result << '\n';

	return 0;
}