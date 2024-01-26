#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int con(int num)
{
	int answer = num;

	while (num != 0)
	{
		answer += num % 10;
		num /= 10;
	}

	return answer;
}

int makeCon(const int num)
{
	for (int i = 1; i <= num; i++)
	{
		const int temp = con(i);

		if (temp == num)
		{
			return i;
		}
	}
	
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	cout << makeCon(N) << '\n';

	return 0;
}