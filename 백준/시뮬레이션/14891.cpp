#include <iostream>
#include <deque>
#include <string>
#include <cmath>
using namespace std;

deque<int> gear[4];

#define CLOCK 1
#define COUNTERCLOCK -1

#define N 0
#define S 1

int leftSide(int gearNum)
{
	int temp1 = gear[gearNum].back();
	gear[gearNum].pop_back();
	int temp2 = gear[gearNum].back();
	gear[gearNum].push_back(temp1);

	return temp2;
}

int rightSide(int gearNum)
{
	int temp1 = gear[gearNum].front();
	gear[gearNum].pop_front();
	int temp2 = gear[gearNum].front();
	gear[gearNum].pop_front();
	int temp3 = gear[gearNum].front();

	gear[gearNum].push_front(temp2);
	gear[gearNum].push_front(temp1);

	return temp3;
}

void clockRoll(int gearNum)
{
	int temp = gear[gearNum].back();
	gear[gearNum].pop_back();
	gear[gearNum].push_front(temp);
}

void counterRoll(int gearNum)
{
	int temp = gear[gearNum].front();
	gear[gearNum].pop_front();
	gear[gearNum].push_back(temp);
}

void clock(int);
void counterClock(int);

void clock(int gearNum)
{
	int rotation[4] = { 0, 0, 0, 0 };

	rotation[gearNum] = CLOCK;

	// left
	for (int i = gearNum - 1; i >= 0; i--)
	{
		int prev = i + 1;

		if (rightSide(i) != leftSide(prev))
		{
			if (rotation[prev] == CLOCK)
			{
				rotation[i] = COUNTERCLOCK;
			}
			else if (rotation[prev] == COUNTERCLOCK)
			{
				rotation[i] = CLOCK;
			}
		}
	}

	// right
	for (int i = gearNum + 1; i < 4; i++)
	{
		int prev = i - 1;

		if (rightSide(prev) != leftSide(i))
		{
			if (rotation[prev] == CLOCK)
			{
				rotation[i] = COUNTERCLOCK;
			}
			else if (rotation[prev] == COUNTERCLOCK)
			{
				rotation[i] = CLOCK;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (rotation[i] == COUNTERCLOCK)
		{
			counterRoll(i);
		}
		else if (rotation[i] == CLOCK)
		{
			clockRoll(i);
		}
	}
}

void counterClock(int gearNum)
{
	int rotation[4] = { 0, 0, 0, 0 };

	rotation[gearNum] = COUNTERCLOCK;

	// left
	for (int i = gearNum - 1; i >= 0; i--)
	{
		int prev = i + 1;

		if (rightSide(i) != leftSide(prev))
		{
			if (rotation[prev] == CLOCK)
			{
				rotation[i] = COUNTERCLOCK;
			}
			else if (rotation[prev] == COUNTERCLOCK)
			{
				rotation[i] = CLOCK;
			}
		}
	}

	// right
	for (int i = gearNum + 1; i < 4; i++)
	{
		int prev = i - 1;

		if (rightSide(prev) != leftSide(i))
		{
			if (rotation[prev] == CLOCK)
			{
				rotation[i] = COUNTERCLOCK;
			}
			else if (rotation[prev] == COUNTERCLOCK)
			{
				rotation[i] = CLOCK;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (rotation[i] == COUNTERCLOCK)
		{
			counterRoll(i);
		}
		else if (rotation[i] == CLOCK)
		{
			clockRoll(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char temp;
	int k;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> temp;

			gear[i].push_back(temp - '0');
		}
	}

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int a, b;

		cin >> a >> b;

		if (b == CLOCK)
		{
			clock(a - 1);
		}
		else if (b == COUNTERCLOCK)
		{
			counterClock(a - 1);
		}
	}

	int result = 0;

	for (int i = 0; i <= 3; i++)
	{
		if (gear[i].front() == S)
		{
			result += pow(2, i);
		}
	}

	cout << result << '\n';

	return 0;
}