#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> answers;

void func(vector<int> &input, int sum)
{
	if (input.size() == 2)
	{
		answers.push_back(sum);

		return;
	}

	for (int i = 1; i < input.size() - 1; i++)
	{
		vector<int> tempVec;
		int temp;

		temp = input[i - 1] * input[i + 1];
		
		for (int j = 0; j < input.size(); j++)
		{
			if (j == i)
			{
				continue;
			}
			tempVec.push_back(input[j]);
		}

		func(tempVec, sum + temp);
	}
}

int main()
{
	vector<int> input;
	int n, temp;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}

	func(input, 0);

	sort(answers.begin(), answers.end());

	cout << answers.back() << '\n';

	return 0;
}