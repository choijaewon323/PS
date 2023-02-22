#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, k;
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
	
	int result = makeSegmentTree(start, mid, node * 2) *
		makeSegmentTree(mid + 1, end, node * 2 + 1);

	if (result > 0)
	{
		return segmentTree[node] = 1;
	}
	else if (result < 0)
	{
		return segmentTree[node] = -1;
	}
	else
	{
		return segmentTree[node] = 0;
	}
}

int findMul(int start, int end, int node, int left, int right)
{
	int mid;

	if (right < start || end < left)
	{
		return 1;
	}

	if (left <= start && end <= right)
	{
		return segmentTree[node];
	}

	mid = (start + end) / 2;

	int result = findMul(start, mid, node * 2, left, right) *
		findMul(mid + 1, end, node * 2 + 1, left, right);

	if (result > 0)
	{
		return 1;
	}
	else if (result < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
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

	int result = segmentTree[node * 2] * segmentTree[node * 2 + 1];

	if (result > 0)
	{
		segmentTree[node] = 1;
	}
	else if (result < 0)
	{
		segmentTree[node] = -1;
	}
	else
	{
		segmentTree[node] = 0;
	}
	return;
}

void input()
{
	while (1)
	{
		string output = "";
		cin >> n >> k;

		if (cin.eof())
		{
			break;
		}


		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		makeSegmentTree(1, n, 1);


		for (int i = 0; i < k; i++)
		{
			char a;
			int b, c;

			cin >> a;

			if (a == 'C')
			{
				cin >> b >> c;
				update(1, n, 1, b, c);
			}
			else
			{
				cin >> b >> c;
				int result = findMul(1, n, 1, b, c);

				if (result > 0)
				{
					output += "+";
				}
				else if (result < 0)
				{
					output += "-";
				}
				else
				{
					output += "0";
				}
			}

		}

		cout << output << '\n';
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