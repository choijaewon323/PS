#include <iostream>
#include <map>
#include <vector>
using namespace std;

int arr[41];
int m[8000001];
int s;
long long cnt;

int indexHash(int number)
{
	return number + 4000000;
}

void func1(int start, int end, int picked, int acc)
{
	if (start > end)
	{
		m[indexHash(acc)]++;

		return;
	}
	func1(start + 1, end, picked + 1, acc + arr[start]);

	func1(start + 1, end, picked, acc);
}

void func2(int start, int end, int picked, int acc)
{
	if (start > end)
	{
		cnt += m[indexHash(s - acc)];

		return;
	}
	func2(start + 1, end, picked + 1, acc + arr[start]);

	func2(start + 1, end, picked, acc);
}

int main()
{
	int n;
	
	cin >> n >> s;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	func1(1, n / 2, 0, 0);
	func2(n / 2 + 1, n, 0, 0);

	if (s == 0)
	{
		cout << cnt - 1 << '\n';
	}
	else
	{
		cout << cnt << '\n';
	}
	
	return 0;
}