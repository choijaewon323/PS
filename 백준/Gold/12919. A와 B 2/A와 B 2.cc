#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int solution(string T, string &S)
{
	if (S == T)
	{
		return 1;
	}

	if (S.size() >= T.size())
	{
		return 0;
	}

	int result = 0;
	if (T.back() == 'A')
	{
		string temp = T;
		temp.erase(temp.size() - 1);
		result = max(result, solution(temp, S));
	}

	if (T[0] == 'B')
	{
		string temp = T;
		reverse(temp.begin(), temp.end());
		temp.erase(temp.size() - 1);
		result = max(result, solution(temp, S));
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string S, T;

	cin >> S;
	cin >> T;

	cout << solution(T, S) << '\n';
	
	return 0;
}