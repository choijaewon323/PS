#include <iostream>
using namespace std;

int main()
{
	int arr[42] = { 0 };
	int num;

	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		if (!arr[num % 42])
		{
			arr[num % 42] = 1;
		}
	}

	int sum = 0;

	for (int i = 0; i < 42; i++)
	{
		sum += arr[i];
	}

	cout << sum << '\n';

	return 0;
}