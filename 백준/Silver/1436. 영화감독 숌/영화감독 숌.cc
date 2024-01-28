#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#include <cmath>

using namespace std;

#define MAX 3000000

vector<int> nums;

bool isInclude(const int num)
{
	int temp = num;
	bool flag = false;
	int cnt = 0;

	while (temp != 0)
	{
		const int present = temp % 10;

		temp /= 10;

		if (present == 6)
		{
			if (!flag)
			{
				flag = true;
				cnt = 1;
			}
			else
			{
				cnt++;

				if (cnt == 3)
				{
					return true;
				}
			}
		}
		else
		{
			if (flag)
			{
				flag = false;
			}
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= MAX; i++)
	{
		if (isInclude(i))
		{
			nums.push_back(i);
		}
	}

	sort(nums.begin(), nums.end());

	cout << nums[N - 1] << '\n';

	return 0;
}