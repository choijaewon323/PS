#include <iostream>
#include <algorithm>

using namespace std;

int matrix[100][100];

int main(int argc, char **argv)
{
	int test_case;
	int T;
	
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int testNum;
		int temp;
		int result = -1;

		cin >> testNum;

		for (int y = 0; y < 100; y++)
		{
			for (int x = 0; x < 100; x++)
			{
				cin >> matrix[y][x];
			}
		}

		// 가로 합
		for (int y = 0; y < 100; y++)
		{
			temp = 0;

			for (int x = 0; x < 100; x++)
			{
				temp += matrix[y][x];
			}
			
			result = max(result, temp);
		}

		// 세로 합
		for (int x = 0; x < 100; x++)
		{
			temp = 0;

			for (int y = 0; y < 100; y++)
			{
				temp += matrix[y][x];
			}

			result = max(result, temp);
		}

		// 왼쪽 대각선
		temp = 0;
		for (int i = 0; i < 100; i++)
		{
			temp += matrix[i][i];
		}
		result = max(result, temp);

		// 오른쪽 대각선
		temp = 0;
		for (int i = 0; i < 100; i++)
		{
			temp += matrix[i][99 - i];
		}
		result = max(result, temp);

		cout << "#" << testNum << " " << result << '\n';
	}

	return 0;
}