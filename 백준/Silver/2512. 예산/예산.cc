#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cost(vector<int> &input, int mid)
{
	int result = 0;

	for (int i : input)
	{
		if (i <= mid)
		{
			result += i;
		}
		else
		{
			result += mid;
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	vector<int> input;

	cin >> N;

	int acc = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;

		cin >> temp;
		acc += temp;
		input.push_back(temp);
	}

	sort(input.begin(), input.end());

	int M;

	cin >> M;

	if (acc <= M)
	{
		cout << input.back() << '\n';

		return 0;
	}

	int left = 0;
	int right = input.back();
	int size = input.size();
	int answer;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		int result = cost(input, mid);

		if (result <= M)
		{
			answer = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << answer << '\n';

	return 0;
}