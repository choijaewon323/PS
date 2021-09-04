#include <iostream>
using namespace std;

int main()
{
	int arr[9];

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}

	int temp = 0;
	int index;

	for (int i = 0; i < 9; i++)
	{
		if (temp < arr[i])
		{
			temp = arr[i];
			index = i + 1;
		}
	}

	cout << temp << '\n' << index << '\n';

	return 0;
}