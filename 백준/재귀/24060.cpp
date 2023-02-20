#include <iostream>
using namespace std;

int n, k;
int arr[500001];
int tmp[500001];
int result = -1;
int tmpSave = 0;

void merge(int, int, int);

void merge_sort(int p, int r)
{
	int q = (p + r) / 2;

	if (p == r)
	{
		return;
	}
	merge_sort(p, q);
	merge_sort(q + 1, r);
	merge(p, q, r);
}

void merge(int p, int q, int r)
{
	int i = p, j = q + 1, t = 1;

	while (i <= q && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			tmp[t++] = arr[i++];
		}
		else
		{
			tmp[t++] = arr[j++];
		}
	}

	while (i <= q)
	{
		tmp[t++] = arr[i++];
	}

	while (j <= r)
	{
		tmp[t++] = arr[j++];
	}

	i = p; t = 1;

	while (i <= r)
	{
		arr[i++] = tmp[t++];
		tmpSave++;

		if (k == tmpSave)
		{
			result = arr[i - 1];
		}
	}
}

void input()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
}

void solution()
{
	merge_sort(1, n);

	cout << result << '\n';
}

int main()
{
	input();
	solution();

	return 0;
}