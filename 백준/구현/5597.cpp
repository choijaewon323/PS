#include <iostream>
#include <algorithm>
using namespace std;

int notSubmit[2];
bool submit[31];

int main()
{
	int temp;
	int index = 0;

	for (int i = 0; i < 28; i++)
	{
		cin >> temp;
		submit[temp] = true;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (!submit[i])
		{
			notSubmit[index++] = i;
		}
	}

	cout << min(notSubmit[0], notSubmit[1]) << '\n';
	cout << max(notSubmit[0], notSubmit[1]) << '\n';

	return 0;
}