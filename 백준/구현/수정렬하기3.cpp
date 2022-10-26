#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	unsigned n;
	int* arr = new int[10001];
	for (int i = 0; i < 10001; i++)
	{
		arr[i] = 0;
	}
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		arr[temp]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (arr[i] == 0)
		{
			continue;
		}
		for (int j = 0; j < arr[i]; j++)
		{
			cout << i << '\n';
		}
	}
	delete[] arr;
	return 0;
}