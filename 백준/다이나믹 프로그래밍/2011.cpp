#include <iostream>
#include <string>
#include <map>
using namespace std;

#define MOD 1000000

map<string, int> m;

int func(string temp)
{
	if (temp.empty())
	{
		return 1;
	}

	if (m[temp] != 0)
	{
		return m[temp];
	}

	int result = 0;

	int n = temp.size();
	if (n >= 1)
	{
		for (int i = 1; i <= 9; i++)
		{
			if (temp[0] == '0' + i)
			{
				result += func(temp.substr(1, n - 1));
				result %= MOD;
			}
		}
	}

	if (n >= 2)
	{
		for (int i = 10; i <= 26; i++)
		{
			string s = temp.substr(0, 2);

			if (s == to_string(i))
			{
				result += func(temp.substr(2, n - 2));
				result %= MOD;
			}
		}
	}

	return m[temp] = result % MOD;
}

int main()
{
	string password;

	cin >> password;

	int answer = func(password);

	cout << answer << '\n';

	return 0;
}