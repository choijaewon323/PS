#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];
long long segTree[4000001];

long long query(int begin, int end, int node, int left, int right)
{
	if (right < begin || end < left)
	{
		return 0;
	}

	if (begin <= left && right <= end)
	{
		return segTree[node];
	}

	int mid = (left + right) / 2;

	return query(begin, end, node * 2, left, mid) + query(begin, end, node * 2 + 1, mid + 1, right);
}

long long update(int index, long long value, int node, int left, int right)
{
	if (index < left || right < index)
	{
		return segTree[node];
	}

	if (left == right)
	{
		return segTree[node] += value;
	}

	int mid = (left + right) / 2;

	return segTree[node] = update(index, value, node * 2, left, mid) + update(index, value, node * 2 + 1, mid + 1, right);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, Q;

	cin >> N >> Q;

	for (int i = 0; i < Q; i++)
	{
		int m;

		cin >> m;

		if (m == 1)
		{
			int p, x;

			cin >> p >> x;

			update(p, x, 1, 1, N);
		}
		else
		{
			int p, q;

			cin >> p >> q;

			long long result = query(p, q, 1, 1, N);

			cout << result << '\n';
		}
	}

	return 0;
}