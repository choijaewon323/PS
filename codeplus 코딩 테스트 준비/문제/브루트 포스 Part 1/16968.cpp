#include <iostream>
#include <string>
#include <vector>
using namespace std;

int func(string &input, vector<char>& plate, int index)
{
	if (plate.size() == input.size())
	{
		return 1;
	}

	int result = 0;

	if (input[index] == 'c')
	{
		for (int i = 0; i < 26; i++)
		{
			if (!plate.empty() && plate.back() - 'a' == i)
			{
				continue;
			}

			plate.push_back('a' + i);
			result += func(input, plate, index + 1);
			plate.pop_back();
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (!plate.empty() && plate.back() - '0' == i)
			{
				continue;
			}

			plate.push_back('0' + i);
			result += func(input, plate, index + 1);
			plate.pop_back();
		}
	}

	return result;
}

int main()
{
	string input;
	vector<char> plate;

	cin >> input;

	cout << func(input, plate, 0) << '\n';

	return 0;
}