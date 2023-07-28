#include <iostream>

using namespace std;

int bucket[101];

int main()
{
	int N, M;

	cin >> N >> M;

	for (int m = 0; m < M; m++)
	{
		int i, j, k;

		cin >> i >> j >> k;

		for (int idx = i; idx <= j; idx++)
		{
			bucket[idx] = k;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << bucket[i] << " ";
	}
	cout << '\n';

	return 0;
}