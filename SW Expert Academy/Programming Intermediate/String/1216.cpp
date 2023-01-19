#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	int test_case;
	int testNum;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		char matrix[100][100];
		int findStr;
		int result = 1;

		cin >> testNum;

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				cin >> matrix[i][j];
			}
		}

		for (int size = 2; size <= 100; size++)
		{
			findStr = size;

			// 행 우선
			for (int i = 0; i < 100; i++)
			{
				for (int j = 0; j <= 100 - findStr; j++)
				{
					string temp = "";
					string revTemp = "";

					for (int k = j; k < j + findStr; k++)
					{
						temp += matrix[i][k];
					}
					for (int k = j + findStr - 1; k >= j; k--)
					{
						revTemp += matrix[i][k];
					}

					if (temp.compare(revTemp) == 0)
					{
						result = max(result, findStr);
					}
				}
			}

			// 열 우선
			for (int i = 0; i < 100; i++)
			{
				for (int j = 0; j <= 100 - findStr; j++)
				{
					string temp = "";
					string revTemp = "";

					for (int k = j; k < j + findStr; k++)
					{
						temp += matrix[k][i];
					}
					for (int k = j + findStr - 1; k >= j; k--)
					{
						revTemp += matrix[k][i];
					}

					if (temp.compare(revTemp) == 0)
					{
						result = max(result, findStr);
					}
				}
			}
		}
		


		cout << "#" << test_case << " " << result << '\n';
	}

	return 0;
}