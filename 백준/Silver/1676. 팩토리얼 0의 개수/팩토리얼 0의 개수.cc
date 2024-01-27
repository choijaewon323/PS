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

#define MAX 50

int N;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	int numOfTwo = 0;
	int numOfFive = 0;

	for (int i = N; i >= 1; i--)
	{
		int num = i;
		while (true)
		{
			if (num % 2 == 0)
			{
				numOfTwo++;
				num /= 2;
			}
			else
			{
				break;
			}
		}

		num = i;
		while (true)
		{
			if (num % 5 == 0)
			{
				numOfFive++;
				num /= 5;
			}
			else
			{
				break;
			}
		}
	}

	cout << min(numOfTwo, numOfFive) << '\n';

	return 0;
}