#include <iostream>
#include <vector>
using namespace std;

bool numberUsed[2000001];

void func(vector<int> &input, vector<int> &subset, int index)
{
	if (index == input.size())	// base case
	{
		if (subset.empty())
		{
			numberUsed[0] = true;
		}
		else
		{
			int result = 0;

			for (auto s : subset)
			{
				result += s;
			}

			numberUsed[result] = true;
		}

		return;
	}

	subset.push_back(input[index]);
	func(input, subset, index + 1);
	subset.pop_back();
	func(input, subset, index + 1);
}

int main()
{
	vector<int> input, subset;
	int n, temp, answer;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}

	func(input, subset, 0);

	for (int i = 1; i < 2000001; i++)
	{
		if (!numberUsed[i])
		{
			answer = i;
			break;
		}
	}

	cout << answer << '\n';

	return 0;
}