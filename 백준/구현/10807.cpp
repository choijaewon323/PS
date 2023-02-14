#include <iostream>
using namespace std;

int arr[100];

int main()
{
	int n;
	int v;
	int result = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cin >> v;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == v)
		{
			result++;
		}
	}

	cout << result << '\n';

	return 0;
}