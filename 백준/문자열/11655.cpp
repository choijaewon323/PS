#include <iostream>
#include <string>
using namespace std;

char rot13(char a)
{
	int index;
	char result;
	if ('A' <= a && a <= 'Z')
	{
		index = a - 'A';
		index = (index + 13) % 26;
		result = 'A' + index;
	}
	else if ('a' <= a && a <= 'z')
	{
		index = a - 'a';
		index = (index + 13) % 26;
		result = 'a' + index;
	}

	return result;
}

int main()
{
	string input;

	getline(cin, input);

	for (int i = 0; i < input.size(); i++)
	{
		if ('A' <= input[i] && input[i] <= 'Z' || 'a' <= input[i] && input[i] <= 'z')
		{
			input[i] = rot13(input[i]);
		}
	}

	cout << input << '\n';

	return 0;
}