#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int n;
vector<pair<int, int>> arr;
vector<ll> tree;

ll findNode(int node, int start, int end, int left, int right)
{
	if (right < start || end < left)
	{
		return 0;
	}

	if (left <= start && end <= right)
	{
		return tree[node];
	}

	int mid = (start + end) / 2;

	ll leftSide = findNode(node * 2, start, mid, left, right);
	ll rightSide = findNode(node * 2 + 1, mid + 1, end, left, right);

	return leftSide + rightSide;
}

void update(int node, int start, int end, int index)
{
	if (start == end)
	{
		tree[node] = 1;
		return;
	}

	int mid = (start + end) / 2;

	if (start <= index && index <= mid)
	{
		update(node * 2, start, mid, index);
	}
	else if (mid + 1 <= index && index <= end)
	{
		update(node * 2 + 1, mid + 1, end, index);
	}

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void input()
{
	cin >> n;

	arr = vector<pair<int, int>>(n + 1);
	tree = vector<ll>(4 * n + 1);
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;

		arr[i] = { temp, i };
	}

	arr[0] = { -1000000001, 0 };
	sort(arr.begin(), arr.end());

	ll result = 0;
	for (int i = 1; i <= n; i++)
	{
		int index = arr[i].second;

		result += findNode(1, 1, n, index + 1, n);
		update(1, 1, n, index);
	}

	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	return 0;
}