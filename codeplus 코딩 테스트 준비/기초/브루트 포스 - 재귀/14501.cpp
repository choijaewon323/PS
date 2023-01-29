#include <iostream>
using namespace std;

int input[50][2];
int n;
int money;

void func(int today, int sum)
{
	if (today > n)
	{
		if (money < sum)
		{
			money = sum;
		}
		return;
	}

	if (today + input[today][0] > n + 1)
	{
		func(today + 1, sum);

		return;
	}

	func(today + input[today][0], sum + input[today][1]);
	func(today + 1, sum);
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> input[i][0] >> input[i][1];
	}
	input[n + 1][0] = 2000;
	
	for (int i = 1; i <= n; i++)
	{
		func(i, 0);
	}

	cout << money << '\n';

	return 0;
}