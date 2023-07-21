#include <iostream>
#include <utility>
using namespace std;
int arr[100001];
pair<int, int> segTree[400001]; // first : 홀수, second : 짝수
pair<int, int> init(int node, int left, int right)
{
	if (left == right)
	{
		if (arr[left] % 2 == 0)
		{
			return segTree[node] = { 0, 1 };
		}
		else
		{
			return segTree[node] = { 1, 0 };
		}
	}
	int mid = (left + right) / 2;
	pair<int, int> leftSum = init(node * 2, left, mid);
	pair<int, int> rightSum = init(node * 2 + 1, mid + 1, right);
	leftSum.first += rightSum.first;
	leftSum.second += rightSum.second;
	return segTree[node] = leftSum;
}
int queryEven(int begin, int end, int node, int left, int right)
{
	if (right < begin || end < left)
	{
		return 0;
	}
	if (begin <= left && right <= end)
	{
		return segTree[node].second;
	}
	int mid = (left + right) / 2;
	int leftSum = queryEven(begin, end, node * 2, left, mid);
	int rightSum = queryEven(begin, end, node * 2 + 1, mid + 1, right);
	return leftSum + rightSum;
}
int queryOdd(int begin, int end, int node, int left, int right)
{
	if (right < begin || end < left)
	{
		return 0;
	}
	if (begin <= left && right <= end)
	{
		return segTree[node].first;
	}
	int mid = (left + right) / 2;
	int leftSum = queryOdd(begin, end, node * 2, left, mid);
	int rightSum = queryOdd(begin, end, node * 2 + 1, mid + 1, right);
	return leftSum + rightSum;
}
pair<int, int> update(int index, int value, int node, int left, int right)
{
	if (index < left || right < index)
	{
		return segTree[node];
	}
	if (left == right)
	{
		if (value % 2 == 0)
		{
			return segTree[node] = { 0, 1 };
		}
		else
		{
			return segTree[node] = { 1, 0 };
		}
	}
	int mid = (left + right) / 2;
	pair<int, int> leftSum = update(index, value, node * 2, left, mid);
	pair<int, int> rightSum = update(index, value, node * 2 + 1, mid + 1, right);
	leftSum.first += rightSum.first;
	leftSum.second += rightSum.second;
	return segTree[node] = leftSum;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	init(1, 1, N);
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int q;
		cin >> q;
		if (q == 1)
		{
			int index, x;
			cin >> index >> x;
			// 업데이트
			update(index, x, 1, 1, N);
		}
		else if (q == 2)
		{
			int l, r;
			cin >> l >> r;
			// 짝수 개수 출력
			int result = queryEven(l, r, 1, 1, N);
			cout << result << '\n';
		}
		else if (q == 3)
		{
			int l, r;
			cin >> l >> r;
			// 홀수 개수 출력
			int result = queryOdd(l, r, 1, 1, N);
			cout << result << '\n';
		}
	}
	return 0;
}