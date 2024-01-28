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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	if (n == 0)
	{
		cout << 0 << '\n';
		return 0;
	}

	vector<int> nums;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	sort(nums.begin(), nums.end());

	const double excludeDouble = nums.size() * 0.15;
	const double rounded = round(excludeDouble) + 0.0;
	const int exclude = (int)rounded;
	
	double acc = 0;
	for (int i = exclude; i < nums.size() - exclude; i++)
	{
		acc += nums[i];
	}

	const double resultRound = round(acc / (nums.size() - 2 * exclude)) + 0.0;
	const int answer = (int)resultRound;

	cout << answer << '\n';

	return 0;
}