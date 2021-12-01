#include <iostream>
using namespace std;
int n, m, k;
int matrixA[100][100];
int matrixB[100][100];
int resultMatrix[100][100];
void matrixMul()
{
	int num = 0;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < k; x++)
		{
			num = 0;
			while (num < m)
			{
				resultMatrix[y][x] += matrixA[y][num] * matrixB[num][x];
				num++;
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> matrixA[i][j];
		}
	}
	cin >> m >> k;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> matrixB[i][j];
		}
	}
	matrixMul();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << resultMatrix[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}