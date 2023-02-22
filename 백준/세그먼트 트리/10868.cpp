#include <iostream>
#include <algorithm>
using namespace std;

int minSegmentTree[400000];
int arr[100001];
int n, m;

int makeMinSegmentTree(int start, int end, int node)
{
	int mid;

	if (start == end)
	{
		return minSegmentTree[node] = arr[start];
	}

	mid = (start + end) / 2;
	return minSegmentTree[node] = min(makeMinSegmentTree(start, mid, node * 2),
		makeMinSegmentTree(mid + 1, end, node * 2 + 1));
}


int findMin(int start, int end, int node, int left, int right)
{
	int mid;

	if (right < start || left > end)
	{
		return INT32_MAX;
	}
	if (left <= start && right >= end)
	{
		return minSegmentTree[node];
	}

	mid = (start + end) / 2;
	return min(findMin(start, mid, node * 2, left, right),
		findMin(mid + 1, end, node * 2 + 1, left, right));
}

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	makeMinSegmentTree(1, n, 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;

		cout << findMin(1, n, 1, a, b) << '\n';
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