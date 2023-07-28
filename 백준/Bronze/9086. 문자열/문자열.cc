#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;

	cin >> T;

	cin.ignore();
	for (int test = 0; test < T; test++)
	{
		string input;

		cin >> input;
		cout << input[0] << input[input.size() - 1] << '\n';
	}

	return 0;
}