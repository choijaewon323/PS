#include <iostream>
#include <map>
#include <string>
using namespace std;

map<int, string> m;

string result;
void func(int n, int b)
{
	if (n == 0)
	{
		return;
	}

	int a = n / b;
	int temp = n % b;
	
	result.insert(0, m[temp]);

	func(a, b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, b;

	cin >> n >> b;

	for (int i = 0; i <= 9; i++)
	{
		m[i] = '0' + i;
	}

	for (int i = 10; i <= 35; i++)
	{
		m[i] = 'A' + (i - 10);
	}

	func(n, b);

	cout << result << '\n';

	return 0;
}