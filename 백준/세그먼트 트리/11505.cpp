#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007

typedef long long ll;

ll mulSegmentTree[4000001];
int arr[1000001];
int n, m, k;

ll makeMulSegmentTree(int start, int end, int node)
{
	int mid;

	if (start == end)
	{
		return mulSegmentTree[node] = arr[start] % MOD;
	}

	mid = (start + end) / 2;
	return mulSegmentTree[node] = (makeMulSegmentTree(start, mid, node * 2) % MOD *
		makeMulSegmentTree(mid + 1, end, node * 2 + 1) % MOD) % MOD;
}


ll findMul(int start, int end, int node, int left, int right)
{
	int mid;

	if (right < start || left > end)
	{
		return 1;
	}
	if (left <= start && right >= end)
	{
		return mulSegmentTree[node] % MOD;
	}

	mid = (start + end) / 2;
	return (findMul(start, mid, node * 2, left, right) % MOD *
		findMul(mid + 1, end, node * 2 + 1, left, right) % MOD) % MOD;
}

void update(int start, int end, int node, int index, int val)
{
	int mid;

	if (start == end)
	{
		mulSegmentTree[node] = val;
		return;
	}

	mid = (start + end) / 2;

	if (index >= start && index <= mid)
	{
		update(start, mid, node * 2, index, val);
	}
	else if (index >= mid + 1 && index <= end)
	{
		update(mid + 1, end, node * 2 + 1, index, val);
	}

	mulSegmentTree[node] = (mulSegmentTree[node * 2] % MOD *
		mulSegmentTree[node * 2 + 1] % MOD) % MOD;
	return;
}

void input()
{
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	makeMulSegmentTree(1, n, 1);

	for (int i = 0; i < m + k; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		if (a == 1)
		{
			update(1, n, 1, b, c);
		}
		else
		{
			cout << findMul(1, n, 1, b, c)  % MOD << '\n';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	return 0;
}