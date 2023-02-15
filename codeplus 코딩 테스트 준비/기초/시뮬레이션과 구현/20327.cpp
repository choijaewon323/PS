#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int arr[128][128];

int pow(int a, int x)
{
	if (x == 0)
	{
		return 1;
	}
	int result = 1;

	return a * pow(a, x - 1);
}

typedef struct _node
{
	vector<vector<int>> sub;
} node;

vector<vector<int>> oper1(int startY, int startX, int endY, int endX)
{
	vector<vector<int>> result;

	for (int y = startY; y <= endY; y++)
	{
		vector<int> temp;
		result.push_back(temp);
		for (int x = startX; x <= endX; x++)
		{
			result.back().push_back(arr[startY + endY - y][x]);
		}
	}

	return result;
}

vector<vector<int>> oper2(int startY, int startX, int endY, int endX)
{
	vector<vector<int>> result;

	for (int y = startY; y <= endY; y++)
	{
		vector<int> temp;
		result.push_back(temp);
		for (int x = startX; x <= endX; x++)
		{
			result.back().push_back(arr[y][startX + endX - x]);
		}
	}

	return result;
}

vector<vector<int>> oper3(int startY, int startX, int endY, int endX)
{
	vector<vector<int>> result;

	for (int x = startX; x <= endX; x++)
	{
		vector<int> temp;
		for (int y = endY; y >= startY; y--)
		{
			temp.push_back(arr[y][x]);
		}
		result.push_back(temp);
	}
	
	return result;
}

vector<vector<int>> oper4(int startY, int startX, int endY, int endX)
{
	vector<vector<int>> result;

	for (int x = endX; x >= startX; x--)
	{
		vector<int> temp;
		for (int y = startY; y <= endY; y++)
		{
			temp.push_back(arr[y][x]);
		}
		result.push_back(temp);
	}

	return result;
}

vector<vector<pair<int, int>>> oper5(vector<vector<pair<int, int>>> &input)
{
	int tempSize = input.size();
	vector<vector<pair<int, int>>> result;

	for (int y = 0; y <= tempSize - 1; y++)
	{
		vector<pair<int, int>> temp;
		for (int x = 0; x <= tempSize - 1; x++)
		{
			temp.push_back(input[tempSize - 1 - y][x]);
		}
		result.push_back(temp);
	}

	return result;
}

vector<vector<pair<int, int>>> oper6(vector<vector<pair<int, int>>> &input)
{
	int tempSize = input.size();
	vector<vector<pair<int, int>>> result;

	for (int y = 0; y <= tempSize - 1; y++)
	{
		vector<pair<int, int>> temp;

		for (int x = 0; x <= tempSize - 1; x++)
		{
			temp.push_back(input[y][tempSize - 1 - x]);
		}

		result.push_back(temp);
	}

	return result;
}

vector<vector<pair<int, int>>> oper7(vector<vector<pair<int, int>>> &input)
{
	int tempSize = input.size();
	vector<vector<pair<int, int>>> result;

	for (int y = 0; y <= tempSize - 1; y++)
	{
		vector<pair<int, int>> temp;

		for (int x = 0; x <= tempSize - 1; x++)
		{
			temp.push_back(input[tempSize - 1 - x][y]);
		}

		result.push_back(temp);
	}
	return result;
}

vector<vector<pair<int, int>>> oper8(vector<vector<pair<int, int>>> &input)
{
	int tempSize = input.size();
	vector<vector<pair<int, int>>> result;

	for (int y = 0; y <= tempSize - 1; y++)
	{
		vector<pair<int, int>> temp;

		for (int x = 0; x <= tempSize - 1; x++)
		{
			temp.push_back(input[x][tempSize - 1 - y]);
		}

		result.push_back(temp);
	}
	return result;
}

void func(int arrSize, int k, int l)
{
	vector<vector<pair<int, int>>> input;
	vector<vector<int>> whole(arrSize, vector<int>(arrSize));
	int tempL = pow(2, l);
	int tempSize = arrSize / tempL;
	int i, j;

	switch (k)
	{
	case 1:
		for (int y = 0; y <= arrSize - 1; y += tempL)
		{
			for (int x = 0; x <= arrSize - 1; x += tempL)
			{
				vector<vector<int>> temp;
				int startY = y;
				int startX = x;
				int endY = y + tempL - 1;
				int endX = x + tempL - 1;

				temp = oper1(startY, startX, endY, endX);
				i = 0; j = 0;

				for (int tempY = startY; tempY <= endY; tempY++)
				{
					for (int tempX = startX; tempX <= endX; tempX++)
					{
						whole[tempY][tempX] = temp[i][j++];
					}
					j = 0;
					i++;
				}
			}
		}
		for (int y = 0; y <= arrSize - 1; y++)
		{
			for (int x = 0; x <= arrSize - 1; x++)
			{
				arr[y][x] = whole[y][x];
			}
		}
		break;
	case 2:
		for (int y = 0; y <= arrSize - 1; y += tempL)
		{
			for (int x = 0; x <= arrSize - 1; x += tempL)
			{
				vector<vector<int>> temp;
				int startY = y;
				int startX = x;
				int endY = y + tempL - 1;
				int endX = x + tempL - 1;

				temp = oper2(startY, startX, endY, endX);
				i = 0; j = 0;

				for (int tempY = startY; tempY <= endY; tempY++)
				{
					for (int tempX = startX; tempX <= endX; tempX++)
					{
						whole[tempY][tempX] = temp[i][j++];
					}
					j = 0;
					i++;
				}
			}
		}
		for (int y = 0; y <= arrSize - 1; y++)
		{
			for (int x = 0; x <= arrSize - 1; x++)
			{
				arr[y][x] = whole[y][x];
			}
		}
		break;
	case 3:
		for (int y = 0; y <= arrSize - 1; y += tempL)
		{
			for (int x = 0; x <= arrSize - 1; x += tempL)
			{
				vector<vector<int>> temp;
				int startY = y;
				int startX = x;
				int endY = y + tempL - 1;
				int endX = x + tempL - 1;

				temp = oper3(startY, startX, endY, endX);
				i = 0; j = 0;

				for (int tempY = startY; tempY <= endY; tempY++)
				{
					for (int tempX = startX; tempX <= endX; tempX++)
					{
						whole[tempY][tempX] = temp[i][j++];
					}
					j = 0;
					i++;
				}
			}
		}
		for (int y = 0; y <= arrSize - 1; y++)
		{
			for (int x = 0; x <= arrSize - 1; x++)
			{
				arr[y][x] = whole[y][x];
			}
		}
		break;
	case 4:
		for (int y = 0; y <= arrSize - 1; y += tempL)
		{
			for (int x = 0; x <= arrSize - 1; x += tempL)
			{
				vector<vector<int>> temp;
				int startY = y;
				int startX = x;
				int endY = y + tempL - 1;
				int endX = x + tempL - 1;

				temp = oper4(startY, startX, endY, endX);
				i = 0; j = 0;

				for (int tempY = startY; tempY <= endY; tempY++)
				{
					for (int tempX = startX; tempX <= endX; tempX++)
					{
						whole[tempY][tempX] = temp[i][j++];
					}
					j = 0;
					i++;
				}
			}
		}
		for (int y = 0; y <= arrSize - 1; y++)
		{
			for (int x = 0; x <= arrSize - 1; x++)
			{
				arr[y][x] = whole[y][x];
			}
		}
		break;
	case 5:
		for (int y = 0; y <= arrSize - 1; y += tempL)
		{
			vector<pair<int, int>> tempInput;
			for (int x = 0; x <= arrSize - 1; x += tempL)
			{
				int startY = y;
				int startX = x;
				int endY = y + tempL - 1;
				int endX = x + tempL - 1;

				tempInput.push_back(make_pair(startY, startX));
			}
			input.push_back(tempInput);
		}

		input = oper5(input);

		for (int y = 0; y <= arrSize - 1; y += tempL)
		{
			for (int x = 0; x <= arrSize - 1; x += tempL)
			{
				pair<int, int> temp;
				int startY = y;
				int startX = x;
				int endY = y + tempL - 1;
				int endX = x + tempL - 1;

				temp = input[y / tempL][x / tempL];
				
				i = temp.first; j = temp.second;

				for (int tempY = startY; tempY <= endY; tempY++)
				{
					for (int tempX = startX; tempX <= endX; tempX++)
					{
						whole[tempY][tempX] = arr[i][j++];
					}
					j = temp.second;
					i++;
				}
			}
		}
		for (int y = 0; y <= arrSize - 1; y++)
		{
			for (int x = 0; x <= arrSize - 1; x++)
			{
				arr[y][x] = whole[y][x];
			}
		}
		break;
	case 6:
		for (int y = 0; y <= arrSize - 1; y += tempL)
		{
			vector<pair<int, int>> tempInput;
			for (int x = 0; x <= arrSize - 1; x += tempL)
			{
				int startY = y;
				int startX = x;
				int endY = y + tempL - 1;
				int endX = x + tempL - 1;

				tempInput.push_back(make_pair(startY, startX));
			}
			input.push_back(tempInput);
		}

		input = oper6(input);

		for (int y = 0; y <= arrSize - 1; y += tempL)
		{
			for (int x = 0; x <= arrSize - 1; x += tempL)
			{
				pair<int, int> temp;
				int startY = y;
				int startX = x;
				int endY = y + tempL - 1;
				int endX = x + tempL - 1;

				temp = input[y / tempL][x / tempL];

				i = temp.first; j = temp.second;

				for (int tempY = startY; tempY <= endY; tempY++)
				{
					for (int tempX = startX; tempX <= endX; tempX++)
					{
						whole[tempY][tempX] = arr[i][j++];
					}
					j = temp.second;
					i++;
				}
			}
		}
		for (int y = 0; y <= arrSize - 1; y++)
		{
			for (int x = 0; x <= arrSize - 1; x++)
			{
				arr[y][x] = whole[y][x];
			}
		}
		break;
	case 7:
		for (int y = 0; y <= arrSize - 1; y += tempL)
		{
			vector<pair<int, int>> tempInput;
			for (int x = 0; x <= arrSize - 1; x += tempL)
			{
				int startY = y;
				int startX = x;
				int endY = y + tempL - 1;
				int endX = x + tempL - 1;
				
				tempInput.push_back(make_pair(startY, startX));
			}
			input.push_back(tempInput);
		}

		input = oper7(input);

		for (int y = 0; y <= arrSize - 1; y += tempL)
		{
			for (int x = 0; x <= arrSize - 1; x += tempL)
			{
				pair<int, int> temp;
				int startY = y;
				int startX = x;
				int endY = y + tempL - 1;
				int endX = x + tempL - 1;

				temp = input[y / tempL][x / tempL];

				i = temp.first; j = temp.second;

				for (int tempY = startY; tempY <= endY; tempY++)
				{
					for (int tempX = startX; tempX <= endX; tempX++)
					{
						whole[tempY][tempX] = arr[i][j++];
					}
					j = temp.second;
					i++;
				}
			}
		}
		for (int y = 0; y <= arrSize - 1; y++)
		{
			for (int x = 0; x <= arrSize - 1; x++)
			{
				arr[y][x] = whole[y][x];
			}
		}
		break;
	case 8:
		for (int y = 0; y <= arrSize - 1; y += tempL)
		{
			vector<pair<int, int>> tempInput;
			for (int x = 0; x <= arrSize - 1; x += tempL)
			{
				int startY = y;
				int startX = x;
				int endY = y + tempL - 1;
				int endX = x + tempL- 1;

				tempInput.push_back(make_pair(startY, startX));
			}
			input.push_back(tempInput);
		}

		input = oper8(input);

		for (int y = 0; y <= arrSize - 1; y += tempL)
		{
			for (int x = 0; x <= arrSize - 1; x += tempL)
			{
				pair<int, int> temp;
				int startY = y;
				int startX = x;
				int endY = y + tempL - 1;
				int endX = x + tempL - 1;

				temp = input[y / tempL][x / tempL];

				i = temp.first; j = temp.second;

				for (int tempY = startY; tempY <= endY; tempY++)
				{
					for (int tempX = startX; tempX <= endX; tempX++)
					{
						whole[tempY][tempX] = arr[i][j++];
					}
					j = temp.second;
					i++;
				}
			}
		}
		for (int y = 0; y <= arrSize - 1; y++)
		{
			for (int x = 0; x <= arrSize - 1; x++)
			{
				arr[y][x] = whole[y][x];
			}
		}
		break;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, r;
	int arrSize;

	cin >> n >> r;

	arrSize = pow(2, n);
	for (int y = 0; y <= arrSize - 1; y++)
	{
		for (int x = 0; x <= arrSize - 1; x++)
		{
			cin >> arr[y][x];
		}
	}

	for (int i = 0; i < r; i++)
	{
		int k, l;

		cin >> k >> l;
		func(arrSize, k, l);
	}

	for (int y = 0; y <= arrSize - 1; y++)
	{
		for (int x = 0; x <= arrSize - 1; x++)
		{
			cout << arr[y][x] << " ";
		}
		cout << '\n';
	}

	return 0;
}