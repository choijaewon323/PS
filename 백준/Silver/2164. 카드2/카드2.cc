#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

deque<int> makeDQ(const int N)
{
	deque<int> result;

	for (int i = 1; i <= N; i++)
	{
		result.push_back(i);
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	deque<int> dq = makeDQ(N);

	while (dq.size() > 1)
	{
		dq.pop_front();

		const int fr = dq.front();
		dq.pop_front();
		dq.push_back(fr);
	}

	cout << dq.front() << '\n';

	return 0;
}