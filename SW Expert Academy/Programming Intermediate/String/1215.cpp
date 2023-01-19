#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	int test_case;
	
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		char matrix[8][8];
		int findStr;
		int result = 0;

		cin >> findStr;
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> matrix[i][j];
			}
		}

		if (findStr == 1)
		{
			cout << "#" << test_case << " " << 64 << '\n';
			continue;
		}

		// 행 우선
		for (int i = 0; i < 8 ; i++)
		{
			for (int j = 0; j <= 8 - findStr; j++)
			{
				string temp = "";
				string revTemp = "";

				for (int k = j; k < j + findStr; k++)
				{
					temp += matrix[i][k];
					revTemp += matrix[i][k];
				}

				reverse(revTemp.begin(), revTemp.end());

				if (temp.compare(revTemp) == 0)
				{
					result++;
				}
			}
		}

		// 열 우선
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j <= 8 - findStr; j++)
			{
				string temp = "";
				string revTemp = "";

				for (int k = j; k < j + findStr; k++)
				{
					temp += matrix[k][i];
					revTemp += matrix[k][i];
				}

				reverse(revTemp.begin(), revTemp.end());

				if (temp.compare(revTemp) == 0)
				{
					result++;
				}
			}
		}

		cout << "#" << test_case << " " << result << '\n';
	}

	return 0;
}