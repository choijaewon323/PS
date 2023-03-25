#include <iostream>
using namespace std;

int64_t sizes[51];
int64_t patty[51];

int64_t makeSize(int level)
{
	if (level == 0)
	{
		return 1;
	}

	if (sizes[level] != 0)
	{
		return sizes[level];
	}

	return sizes[level] = 1 + makeSize(level - 1) + 1 + makeSize(level - 1) + 1;
}

int64_t makePatty(int level)
{
	if (level == 0)
	{
		return 1;
	}

	if (patty[level] != 0)
	{
		return patty[level];
	}

	return patty[level] = makePatty(level - 1) + 1 + makePatty(level - 1);
}

int64_t func(int level, int64_t x)
{
	if (x <= 0)
	{
		return 0;
	}
	if (level == 0 && x >= 1)
	{
		return 1;
	}
	if (sizes[level] <= x)
	{
		return patty[level];
	}
	int64_t result = 0;

	// 햄버거번
	x--;

	// l-1버거
	result += func(level - 1, x);
	x -= sizes[level - 1];

	// 패티
	if (x >= 1)
	{
		x--;
		result++;
	}

	// l-1버거
	result += func(level - 1, x);
	x -= sizes[level - 1];
	
	// 햄버거번
	x--;

	return result;
}

int main()
{
	int n;
	int64_t x;

	// 사이즈 만들기
	makeSize(50);
	makePatty(50);
	sizes[0] = 1;
	patty[0] = 1;

	cin >> n >> x;

	int64_t result = func(n, x);

	cout << result << '\n';
	
	return 0;
}