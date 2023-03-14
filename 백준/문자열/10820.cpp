#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;

	while (true)
	{
		getline(cin, input);

		if (cin.eof())
		{
			break;
		}

		int lower = 0;
		int upper = 0;
		int num = 0;
		int space = 0;

		for (auto i : input)
		{
			if ('a' <= i && i <= 'z')
			{
				lower++;
				continue;
			}
			if ('A' <= i && i <= 'Z')
			{
				upper++;
				continue;
			}
			if ('0' <= i && i <= '9')
			{
				num++;
			}
			if (' ' == i)
			{
				space++;
			}
		}

		cout << lower << " " << upper << " " << num << " " << space << '\n';
	}

	return 0;
}