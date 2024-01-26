#include <iostream>
#include <string>

using namespace std;

string str;

void solve();

void input()
{
	while (true)
	{
		cin >> str;
		if (str == "0")
		{
			return;
		}

		solve();
	}
}

void solve()
{
	int left = 0;
	int right = str.size() - 1;

	while (left <= right)
	{
		if (str[left] != str[right])
		{
			cout << "no" << '\n';
			return;
		}
		
		left++;
		right--;
	}

	cout << "yes" << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	
	return 0;
}