#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100001];
int segmentTree[400001];

int makeSegmentTree(int start, int end, int node)
{
	int mid;

	if (start == end)
	{
		return segmentTree[node] = arr[start];
	}

	mid = (start + end) / 2;
	return segmentTree[node] = min(makeSegmentTree(start, mid, node * 2),
		makeSegmentTree(mid + 1, end, node * 2 + 1));
}

int findMin(int start, int end, int node, int left, int right)
{
	int mid;

	if (right < start || end < left)
	{
		return INT32_MAX;
	}

	if (left <= start && end <= right)
	{
		return segmentTree[node];
	}

	mid = (start + end) / 2;

	return min(findMin(start, mid, node * 2, left, right),
		findMin(mid + 1, end, node * 2 + 1, left, right));
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

	segmentTree[node] = min(segmentTree[node * 2], segmentTree[node * 2 + 1]);
	return;
}

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	makeSegmentTree(1, n, 1);

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		if (a == 1)
		{
			update(1, n, 1, b, c);
		}
		else
		{
			cout << findMin(1, n, 1, b, c) << '\n';
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