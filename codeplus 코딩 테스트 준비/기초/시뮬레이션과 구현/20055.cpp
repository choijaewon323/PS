#include <iostream>
#include <queue>
using namespace std;

queue<int> robots;
bool robotIndex[201];
int arr[201];
int n, k;

// 1단계
void level1()
{
	// 로봇 돌리기
	int size = robots.size();
	for (int i = 0; i < size; i++)
	{
		int temp = robots.front();
		robots.pop();

		robotIndex[temp] = false;

		temp++;
		if (temp == n)
		{
			continue;
		}
		else
		{
			robotIndex[temp] = true;
			robots.push(temp);
		}
	}

	// 벨트 돌리기
	int temp = arr[n * 2];
	for (int i = 2 * n - 1; i >= 1; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[1] = temp;
}

// 2단계
void level2()
{
	int size = robots.size();
	for (int i = 0; i < size; i++)
	{
		int temp = robots.front();
		robots.pop();

		if (!robotIndex[temp + 1] && arr[temp + 1] >= 1)
		{
			robotIndex[temp] = false;
			arr[temp + 1]--;
			temp++;
			
			if (temp == n)
			{
				continue;
			}
			else
			{
				robotIndex[temp] = true;
				robots.push(temp);
			}
		}
		else
		{
			robots.push(temp);
		}
	}
}

// 3단계
void level3()
{
	if (arr[1] != 0)
	{
		arr[1]--;
		robots.push(1);
		robotIndex[1] = true;
	}
}

// 4단계
bool level4()
{
	int countZero = 0;

	for (int i = 1; i <= 2 * n; i++)
	{
		if (arr[i] == 0)
		{
			countZero++;
		}
	}

	if (countZero >= k)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	cin >> n >> k;

	for (int i = 1; i <= 2 * n; i++)
	{
		cin >> arr[i];
	}

	int count = 0;
	while (1)
	{
		count++;
		level1();
		level2();
		level3();
		bool result = level4();

		if (!result)
		{
			break;
		}
	}

	cout << count << '\n';

	return 0;
}