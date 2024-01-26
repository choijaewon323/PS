#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 10000

int numbers[MAX + 1];

void print(const int num)
{
	const int cnt = numbers[num];

	for (int i = 0; i < cnt; i++)
	{
		cout << num << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		numbers[temp]++;
	}

	for (int num = 1; num <= 10000; num++)
	{
		if (numbers[num] != 0)
		{
			print(num);
		}
	}
	
	return 0;
}