#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

#define R 31
#define M 1234567891

ll power(const int up)
{
	if (up == 0)
	{
		return 1;
	}

	return R * power(up - 1) % M;
}

int charToInt(const char c)
{
	return (c - 'a') + 1;
}

ll hashFunc(const int num, const int i)
{
	return num * power(i) % M;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int L;
	cin >> L;

	string input;
	cin >> input;

	ll answer = 0;
	for (int i = 0; i < L; i++)
	{
		const char c = input[i];

		const int num = charToInt(c);
		answer += hashFunc(num, i);
		answer %= M;
	}

	cout << answer << '\n';
	
	return 0;
}