#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	int test_case;
	int testNum;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		string findStr;
		string wholeStr;
		int result = 0;
		bool flag = true;

		cin >> testNum;

		cin >> findStr;
		cin >> wholeStr;

		for (int i = 0; i <= wholeStr.size() - findStr.size(); i++)
		{
			flag = true;
			for (int j = 0; j < findStr.size(); j++)
			{
				if (findStr[j] != wholeStr[i + j])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				result++;
			}
		}

		cout << "#" << test_case << " " << result << '\n';

	}
	return 0;
}