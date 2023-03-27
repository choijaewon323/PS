#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 30

typedef struct _node
{
	int y;
	int x;
	int d1;
	int d2;
} node;

int n;
int people[30][30];
vector<node> divs;

void divideSection(int y, int x, int d1, int d2)
{
	if (1 <= y && y < y + d1 + d2 && y + d1 + d2 <= n &&
		1 <= x - d1 && x - d1 < x && x < x + d2 && x + d2 <= n)
	{
		divs.push_back({ y, x, d1, d2 });
	}
}

int section5(vector<vector<int>> &temp, node& div)
{
	int result = 0;

	// 경계선 만들기
	for (int y = div.y, x = div.x; y <= div.y + div.d1 && x >= div.x - div.d1; y++, x--)
	{
		temp[y][x] = 5;
	}

	for (int y = div.y, x = div.x; y <= div.y + div.d2 && x <= div.x + div.d2; y++, x++)
	{
		temp[y][x] = 5;
	}

	for (int y = div.y + div.d1, x = div.x - div.d1; y <= div.y + div.d1 + div.d2 && x <= div.x - div.d1 + div.d2; y++, x++)
	{
		temp[y][x] = 5;
	}

	for (int y = div.y + div.d2, x = div.x + div.d2; y <= div.y + div.d2 + div.d1 && x >= div.x + div.d2 - div.d1; y++, x--)
	{
		temp[y][x] = 5;
	}

	// 내부 채우기
	for (int y = 1; y <= n; y++)
	{
		bool toggle = false;
		for (int x = 1; x <= n; x++)
		{
			if ((y == div.y || y == div.y + div.d1 + div.d2) &&
				temp[y][x] == 5)
			{
				result += people[y][x];
			}
			else if (div.y < y && y < div.y + div.d1 + div.d2)
			{
				if (!toggle && temp[y][x] == 5)
				{
					toggle = true;
					result += people[y][x];
				}
				else if (toggle && temp[y][x] != 5)
				{
					temp[y][x] = 5;
					result += people[y][x];
				}
				else if (toggle && temp[y][x] == 5)
				{
					toggle = false;
					result += people[y][x];
				}
			}
		}
	}

	return result;
}

int section1(vector<vector<int>> &temp, node &div)
{
	int result = 0;

	for (int y = 1; y < div.y + div.d1; y++)
	{
		for (int x = 1; x <= div.x; x++)
		{
			if (temp[y][x] == 5)
			{
				continue;
			}
			temp[y][x] = 1;
			result += people[y][x];
		}
	}

	return result;
}

int section2(vector<vector<int>> &temp, node &div)
{
	int result = 0;

	for (int y = 1; y <= div.y + div.d2; y++)
	{
		for (int x = div.x + 1; x <= n; x++)
		{
			if (temp[y][x] == 5)
			{
				continue;
			}
			temp[y][x] = 2;
			result += people[y][x];
		}
	}

	return result;
}

int section3(vector<vector<int>> &temp, node &div)
{
	int result = 0;

	for (int y = div.y + div.d1; y <= n; y++)
	{
		for (int x = 1; x < div.x - div.d1 + div.d2; x++)
		{
			if (temp[y][x] == 5)
			{
				continue;
			}
			temp[y][x] = 3;
			result += people[y][x];
		}
	}

	return result;
}

int section4(vector<vector<int>> &temp, node &div)
{
	int result = 0;

	for (int y = div.y + div.d2 + 1; y <= n; y++)
	{
		for (int x = div.x - div.d1 + div.d2; x <= n; x++)
		{
			if (temp[y][x] == 5)
			{
				continue;
			}
			temp[y][x] = 4;
			result += people[y][x];
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	// 입력 및 선거구 나누는 방법 만들기
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			cin >> people[y][x];

			for (int d1 = 1; d1 <= x - 1; d1++)
			{
				for (int d2 = 1; d2 <= n - x; d2++)
				{
					divideSection(y, x, d1, d2);
				}
			}
		}
	}

	int answer = INT32_MAX;
	for (auto& div : divs)
	{
		vector<vector<int>> temp(n + 1, vector<int>(n + 1, 0));
		int maxPeople = -1;
		int minPeople = INT32_MAX;
		int tempPeople;

		// 5번 구역 만들기
		tempPeople = section5(temp, div);
		maxPeople = max(maxPeople, tempPeople);
		minPeople = min(minPeople, tempPeople);

		// 1번 구역 만들기
		tempPeople = section1(temp, div);
		maxPeople = max(maxPeople, tempPeople);
		minPeople = min(minPeople, tempPeople);

		// 2번 구역 만들기
		tempPeople = section2(temp, div);
		maxPeople = max(maxPeople, tempPeople);
		minPeople = min(minPeople, tempPeople);

		// 3번 구역 만들기
		tempPeople = section3(temp, div);
		maxPeople = max(maxPeople, tempPeople);
		minPeople = min(minPeople, tempPeople);

		// 4번 구역 만들기
		tempPeople = section4(temp, div);
		maxPeople = max(maxPeople, tempPeople);
		minPeople = min(minPeople, tempPeople);

		answer = min(answer, maxPeople - minPeople);
	}

	cout << answer << '\n';
	
	return 0;
}