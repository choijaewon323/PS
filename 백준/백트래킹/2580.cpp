#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int section(int y, int x)
{
	int ret;

	switch (y)
	{
	case 0:
	case 1:
	case 2:
		switch (x)
		{
		case 0:
		case 1:
		case 2:
			ret = 0;
			break;
		case 3:
		case 4:
		case 5:
			ret = 1;
			break;
		case 6:
		case 7:
		case 8:
			ret = 2;
			break;
		}
		break;
	case 3:
	case 4:
	case 5:
		switch (x)
		{
		case 0:
		case 1:
		case 2:
			ret = 3;
			break;
		case 3:
		case 4:
		case 5:
			ret = 4;
			break;
		case 6:
		case 7:
		case 8:
			ret = 5;
			break;
		}
		break;
	case 6:
	case 7:
	case 8:
		switch (x)
		{
		case 0:
		case 1:
		case 2:
			ret = 6;
			break;
		case 3:
		case 4:
		case 5:
			ret = 7;
			break;
		case 6:
		case 7:
		case 8:
			ret = 8;
			break;
		}
		break;
	}

	return ret;
}

int sectionY[9][9] = {
	{0,0,0,1,1,1,2,2,2},
	{0,0,0,1,1,1,2,2,2},
	{0,0,0,1,1,1,2,2,2},
	{3,3,3,4,4,4,5,5,5},
	{3,3,3,4,4,4,5,5,5},
	{3,3,3,4,4,4,5,5,5},
	{6,6,6,7,7,7,8,8,8},
	{6,6,6,7,7,7,8,8,8},
	{6,6,6,7,7,7,8,8,8}
};

int sectionX[9][9] = {
	{0,1,2,0,1,2,0,1,2},
	{3,4,5,3,4,5,3,4,5},
	{6,7,8,6,7,8,6,7,8},
	{0,1,2,0,1,2,0,1,2},
	{3,4,5,3,4,5,3,4,5},
	{6,7,8,6,7,8,6,7,8},
	{0,1,2,0,1,2,0,1,2},
	{3,4,5,3,4,5,3,4,5},
	{6,7,8,6,7,8,6,7,8}
};

int input[9][9];
vector<pair<int, int>> zeros;
int numOfZero;
bool isPrinted;
int result;

void func(int index)
{
	if (isPrinted)
	{
		return;
	}

	if (index == zeros.size())
	{
		if (numOfZero == 0)
		{
			isPrinted = true;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					cout << input[i][j] << " ";
				}
				cout << '\n';
			}
		}
		return;
	}

	bool isUsed[10];
	for (int i = 0; i < 10; i++)
	{
		isUsed[i] = false;
	}

	int tempY = zeros[index].first;
	int tempX = zeros[index].second;

	for (int i = 0; i < 9; i++)
	{
		isUsed[input[tempY][i]] = true;
	}
	for (int i = 0; i < 9; i++)
	{
		isUsed[input[i][tempX]] = true;
	}
	int sectionNum = section(tempY, tempX);
	for (int i = 0; i < 9; i++)
	{
		isUsed[input [sectionY[sectionNum][i]] [sectionX[sectionNum][i]] ] = true;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (!isUsed[i])
		{
			input[tempY][tempX] = i;
			numOfZero--;
			func(index + 1);
			input[tempY][tempX] = 0;
			numOfZero++;
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> input[i][j];

			if (input[i][j] == 0)
			{
				zeros.push_back(make_pair(i, j));
				numOfZero++;
			}
		}
	}

	func(0);

	return 0;
}