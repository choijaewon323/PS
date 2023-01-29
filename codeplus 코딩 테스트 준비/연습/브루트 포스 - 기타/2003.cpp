#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, answer;
vector<int> seq;

void func(int start, int end)
{
	if (start > end)
	{
		func(start, end + 1);
		return;
	}

	if (end > n)
	{
		for (int i = start + 1; i <= end - 1; i++)
		{
			if (seq[end - 1] - seq[i - 1] == m)
			{
				answer++;
			}
		}

		return;
	}

	if (seq[end] - seq[start - 1] < m)
	{
		func(start, end + 1);
	}
	else if (seq[end] - seq[start - 1] > m)
	{
		func(start + 1, end);
	}
	else
	{
		answer++;
		func(start, end + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int acc;
	cin >> n >> m;

	acc = 0;
	seq.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		acc += temp;
		seq.push_back(acc);
	}

	func(1, 1);

	cout << answer << '\n';

	return 0;
}