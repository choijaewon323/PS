#include <iostream>

using namespace std;

int matrix[102][102];

int main(int argc, char **argv)
{
	int test_case;
	
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int testNum;
		int startY, startX;
		cin >> testNum;

		for (int y = 1; y <= 100; y++)
		{
			for (int x = 1; x <= 100; x++)
			{
				cin >> matrix[y][x];
			}
		}

		for (int i = 1; i <= 100; i++)
		{
			if (matrix[100][i] == 2)
			{
				startY = 100;
				startX = i;
				break;
			}
		}

		while (startY != 1)
		{
			if (matrix[startY][startX - 1])	// 왼쪽 가능
			{
				matrix[startY][startX] = 0;
				startX--;
			}
			else if (matrix[startY][startX + 1])	// 오른쪽 가능
			{
				matrix[startY][startX] = 0;
				startX++;
			}
			else if (matrix[startY - 1][startX])	// 위쪽 가능
			{
				matrix[startY][startX] = 0;
				startY--;
			}
		}

		cout << "#" << test_case << " " << startX - 1 << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}