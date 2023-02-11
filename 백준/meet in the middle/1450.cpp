#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
vector<ll> res1, res2;
int input[30];

void makeWeight(vector<int> &subInput, vector<ll> &res, ll picked, int index)
{
	if (index == subInput.size())
	{
		res.push_back(picked);
		return;
	}

	// 안 넣기
	makeWeight(subInput, res, picked, index + 1);
	// 넣기
	makeWeight(subInput, res, picked + subInput[index], index + 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> div1, div2;
	ll answer;
	unsigned int n, c;

	cin >> n >> c;

	for (int i = 0; i < n; i++)
	{
		int temp;
		
		cin >> temp;
		input[i] = temp;
	}

	for (int i = 0; i < n / 2; i++)
	{
		div1.push_back(input[i]);
	}

	for (int i = n / 2; i < n; i++)
	{
		div2.push_back(input[i]);
	}

	makeWeight(div1, res1, 0, 0);
	makeWeight(div2, res2, 0, 0);

	answer = 0;

	sort(res2.begin(), res2.end());

	for (int i = 0; i < res1.size(); i++)
	{
		answer += upper_bound(res2.begin(), res2.end(), c - res1[i]) - res2.begin();
	}

	cout << answer << '\n';

	return 0;
}