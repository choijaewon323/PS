#include <iostream>
using namespace std;

#define MAX 1024

int arr[MAX + 1][MAX + 1];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			int temp;
			cin >> temp;

			arr[y][x] = temp + arr[y - 1][x] + arr[y][x - 1] - arr[y - 1][x - 1];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;

		cin >> y1 >> x1 >> y2 >> x2;

		int ans = arr[y2][x2] - arr[y2][x1 - 1] - arr[y1 - 1][x2] + arr[y1 - 1][x1 - 1];

		cout << ans << '\n';
	}

	return 0;
}