#include <iostream>
#include <string>
using namespace std;

char monitor[50][200];
int s;

void one(int x, char num);
void two(int x, char num);
void three(int x, char num);
void four(int x, char num);
void five(int x, char num);
void six(int x, char num);
void seven(int x, char num);
void eight(int x, char num);
void nine(int x, char num);
void zero(int x, char num);


void func(int x, char num)
{
	switch (num)
	{
	case '1':
		one(x, num);
		break;
	case '2':
		two(x, num);
		break;
	case '3':
		three(x, num);
		break;
	case '4':
		four(x, num);
		break;
	case '5':
		five(x, num);
		break;
	case '6':
		six(x, num);
		break;
	case '7':
		seven(x, num);
		break;
	case '8':
		eight(x, num);
		break;
	case '9':
		nine(x, num);
		break;
	case '0':
		zero(x, num);
		break;
	}
}

int main()
{
	string n;
	int startX;

	cin >> s;
	cin.ignore();
	cin >> n;

	for (int y = 0; y < 50; y++)
	{
		for (int x = 0; x < 200; x++)
		{
			monitor[y][x] = ' ';
		}
	}

	startX = 1;
	for (auto c : n)
	{
		func(startX, c);
		startX += s + 2 + 1;
	}

	for (int y = 1; y <= 2 * s + 3; y++)
	{
		for (int x = 1; x < n.size() * (s + 3); x++)
		{
			cout << monitor[y][x];
		}
		cout << " " << '\n';
	}

	return 0;
}


void one(int x, char num)
{
	// | 추가
	int startY = 2;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x + s + 1] = '|';
		startY++;
	}
	startY++;
	for (int i = 0; i < s; i++)
	{
		monitor[startY][x + s + 1] = '|';
		startY++;
	}
}

void two(int x, char num)
{
	// | 추가
	int startY = 1;

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x + s + 1] = '|';
		startY++;
	}

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x] = '|';
		startY++;
	}

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;
}

void three(int x, char num)
{
	// | 추가
	int startY = 1;

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x + s + 1] = '|';
		startY++;
	}

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x + s + 1] = '|';
		startY++;
	}

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;
}

void four(int x, char num)
{
	// | 추가
	int startY = 2;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x] = '|';
		monitor[startY][x + s + 1] = '|';
		startY++;
	}

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x + s + 1] = '|';
		startY++;
	}
}

void five(int x, char num)
{
	// | 추가
	int startY = 1;

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x] = '|';
		startY++;
	}

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x + s + 1] = '|';
		startY++;
	}

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;
}

void six(int x, char num)
{
	// | 추가
	int startY = 1;

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x] = '|';
		startY++;
	}

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x] = '|';
		monitor[startY][x + s + 1] = '|';
		startY++;
	}

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;
}

void seven(int x, char num)
{
	// | 추가
	int startY = 1;

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x + s + 1] = '|';
		startY++;
	}
	startY++;
	for (int i = 0; i < s; i++)
	{
		monitor[startY][x + s + 1] = '|';
		startY++;
	}
}

void eight(int x, char num)
{
	// | 추가
	int startY = 1;

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x] = '|';
		monitor[startY][x + s + 1] = '|';
		startY++;
	}

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x] = '|';
		monitor[startY][x + s + 1] = '|';
		startY++;
	}

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;
}

void nine(int x, char num)
{
	// | 추가
	int startY = 1;

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x] = '|';
		monitor[startY][x + s + 1] = '|';
		startY++;
	}

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x + s + 1] = '|';
		startY++;
	}

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;
}

void zero(int x, char num)
{
	// | 추가
	int startY = 1;

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;

	for (int i = 0; i < s; i++)
	{
		monitor[startY][x] = '|';
		monitor[startY][x + s + 1] = '|';
		startY++;
	}
	startY++;
	for (int i = 0; i < s; i++)
	{
		monitor[startY][x] = '|';
		monitor[startY][x + s + 1] = '|';
		startY++;
	}

	for (int i = x + 1; i <= x + s; i++)
	{
		monitor[startY][i] = '-';
	}
	startY++;
}
