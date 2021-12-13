#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	string input;
	map<int, string> numbers;
	map<string, int> names;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		names[input] = i;
		numbers[i] = input;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		if (input[0] >= '0' && input[0] <= '9')
		{
			cout << numbers[stoi(input)] << '\n';
		}
		else
		{
			cout << names[input] << '\n';
		}
	}
	return 0;
}