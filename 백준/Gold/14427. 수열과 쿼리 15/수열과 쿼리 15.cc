#include <iostream>
#include <utility>
#include <limits>

using namespace std;

int arr[100001];
pair<int, int> segTree[400001];

pair<int, int> init(int node, int left, int right)
{
	if (left == right)
	{
		return segTree[node] = { arr[left], left };
	}

	int mid = (left + right) / 2;

	// left
	pair<int, int> leftMin = init(node * 2, left, mid);

	// right
	pair<int, int> rightMin = init(node * 2 + 1, mid + 1, right);

	if (leftMin.first == rightMin.first)
	{
		return segTree[node] = leftMin;
	}
	if (leftMin.first < rightMin.first)
	{
		return segTree[node] = leftMin;
	}
	
	return segTree[node] = rightMin;
}

pair<int, int> query(int left, int right, int node, int nodeLeft, int nodeRight)
{
	if (right < nodeLeft || nodeRight < left)
	{
		return { 1000000001, -1 };
	}

	if (left <= nodeLeft && nodeRight <= right)
	{
		return segTree[node];
	}

	int mid = (nodeLeft + nodeRight) / 2;

	// left
	pair<int, int> leftMin = query(left, right, node * 2, nodeLeft, mid);

	// right
	pair<int, int> rightMin = query(left, right, node * 2 + 1, mid + 1, nodeRight);

	if (leftMin.first == rightMin.first)
	{
		return leftMin;
	}
	if (leftMin.first < rightMin.first)
	{
		return leftMin;
	}

	return rightMin;
}

pair<int, int> update(int index, int value, int node, int nodeLeft, int nodeRight)
{
	if (index < nodeLeft || index > nodeRight)
	{
		return segTree[node];
	}

	if (nodeLeft == nodeRight)
	{
		return segTree[node] = { value, index };
	}

	int mid = (nodeLeft + nodeRight) / 2;

	// left
	pair<int, int> leftMin = update(index, value, node * 2, nodeLeft, mid);

	// right
	pair<int, int> rightMin = update(index, value, node * 2 + 1, mid + 1, nodeRight);

	if (leftMin.first == rightMin.first)
	{
		return segTree[node] = leftMin;
	}
	if (leftMin.first < rightMin.first)
	{
		return segTree[node] = leftMin;
	}

	return segTree[node] = rightMin;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	init(1, 1, n);

	int m;

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int q;

		cin >> q;

		if (q == 1)
		{
			int index, v;

			cin >> index >> v;

			update(index, v, 1, 1, n);
		}
		else if (q == 2)
		{
			int left, right;

			left = 1;
			right = n;
			
			pair<int, int> result = query(left, right, 1, 1, n);

			cout << result.second << '\n';
		}
	}

	return 0;
}