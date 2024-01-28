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

/*
	1일차 : 6 - 2 = 4
	2일차 : 10 - 2 = 8
	3일차 : 14 - 2 = 12
	4일차 : 16
*/

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A, B, V;
	cin >> A >> B >> V;

	int answer = 0;

	// V - A 만큼 올라가기
	const int toMiddle = V - A;
	answer += toMiddle / (A - B);

	const int rest = toMiddle % (A - B);
	int tempHeight = V - A - rest;

	while (true)
	{
		// up
		answer++;
		tempHeight += A;

		if (tempHeight >= V)
		{
			break;
		}

		tempHeight -= B;
	}

	cout << answer << '\n';

	return 0;
}