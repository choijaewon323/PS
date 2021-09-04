#include <iostream>
#include <limits.h>
using namespace std;

int board(int n, int m);

char chessBoard[50][50];

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> chessBoard[i][j];
		}
	}

	int result = INT_MAX, temp;

	for(int i = 0; i <= n - 8; i++)
	{
		for(int j = 0; j <= m - 8; j++)
		{
			temp = board(i, j);
			
			if(result > temp)
			{
				result = temp;
			}
		}
	}

	cout << result << '\n';

	return 0;
}

int board(int n, int m)
{
	int result1 = 0, result2 = 0;

	// ¸Ç ¿ÞÂÊ »ó´Ü °ËÀº»ö
	for(int i = n; i < n + 8; i++)
	{
		for(int j = m; j < m + 8; j++)
		{
			if((i - n) % 2 == 0)
			{
				if((j - m) % 2 == 0)
				{
					if(chessBoard[i][j] == 'W')
					{
						result1++;
					}
				}
				else
				{
					if(chessBoard[i][j] == 'B')
					{
						result1++;
					}
				}
			}
			else
			{
				if((j - m) % 2 == 0)
				{
					if(chessBoard[i][j] == 'B')
					{
						result1++;
					}
				}
				else
				{
					if(chessBoard[i][j] == 'W')
					{
						result1++;
					}
				}
			}
		}
	}

	// ¸Ç ¿ÞÂÊ »ó´Ü Èò»ö
	for(int i = n; i < n + 8; i++)
	{
		for(int j = m; j < m + 8; j++)
		{
			if((i - n) % 2 == 0)
			{
				if((j - m) % 2 == 0)
				{
					if(chessBoard[i][j] == 'B')
					{
						result2++;
					}
				}
				else
				{
					if(chessBoard[i][j] == 'W')
					{
						result2++;
					}
				}
			}
			else
			{
				if((j - m) % 2 == 0)
				{
					if(chessBoard[i][j] == 'W')
					{
						result2++;
					}
				}
				else
				{
					if(chessBoard[i][j] == 'B')
					{
						result2++;
					}
				}
			}
		}
	}

	if(result1 > result2) return result2;
	else return result1;
}