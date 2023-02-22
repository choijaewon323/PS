#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, q;
ll arr[100001];
ll segmentTree[400001];

ll makeSegmentTree(int start, int end, int node)
{
	int mid;

	if (start == end)
	{
		return segmentTree[node] = arr[start];
	}

	mid = (start + end) / 2;

	return segmentTree[node] = makeSegmentTree(start, mid, node * 2) +
		makeSegmentTree(mid + 1, end, node * 2 + 1);
}

ll findSum(int start, int end, int node, int left, int right)
{
	int mid;

	if (right < start || left > end)
	{
		return 0;
	}

	if (left <= start && end <= right)
	{
		return segmentTree[node];
	}

	mid = (start + end) / 2;
	return findSum(start, mid, node * 2, left, right) +
		findSum(mid + 1, end, node * 2 + 1, left, right);

}

void update(int start, int end, int node, int index, int val)
{
	int mid;

	if (start == end)
	{
		segmentTree[node] = val;
		return;
	}

	mid = (start + end) / 2;

	if (start <= index && index <= mid)
	{
		update(start, mid, node * 2, index, val);
	}
	else if (mid + 1 <= index && index <= end)
	{
		update(mid + 1, end, node * 2 + 1, index, val);
	}

	segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];

	return;
}

void input()
{
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	makeSegmentTree(1, n, 1);

	for (int i = 0; i < q; i++)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		cout << findSum(1, n, 1, min(x, y), max(x, y)) << '\n';

		update(1, n, 1, a, b);
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