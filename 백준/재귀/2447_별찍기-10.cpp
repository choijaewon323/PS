#include <iostream>
using namespace std;

char matrix[6561][6561];

void func(int n, int y, int x) 
{
	if (n == 1)
	{
		return;
	}

	for (int i = y; i < y + n / 3; i++)
	{
		for (int j = x; j < x + n / 3; j++)
		{
			matrix[i][j] = ' ';
		}
	}

	int temp = n / 3;
	int tempY = y + (temp / 3);
	int tempX = x + (temp / 3);

	func(n / 3, tempY - temp, tempX - temp);
	func(n / 3, tempY - temp, tempX);
	func(n / 3, tempY - temp, tempX + temp);

	func(n / 3, tempY, tempX - temp);
	func(n / 3, tempY, tempX + temp);

	func(n / 3, tempY + temp, tempX - temp);
	func(n / 3, tempY + temp, tempX);
	func(n / 3, tempY + temp, tempX + temp);
}

int main()
{
	int n;

	for (int i = 0; i < 6561; i++)
	{
		for (int j = 0; j < 6561; j++)
		{
			matrix[i][j] = '*';
		}
	}

	cin >> n;
	func(n, n/3,n/3);
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j];
		}
		cout << '\n';
	}

	return 0;
}