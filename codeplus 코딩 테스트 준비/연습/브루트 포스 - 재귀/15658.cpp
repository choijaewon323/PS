#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> answers;
int operCount[4];
int n;

void func(vector<int> &input, vector<int> &operators)
{
	if (operators.size() == n - 1)
	{
		stack<int> numbers;
		int temp1, temp2;

		for (int i = input.size() - 1; i >= 0; i--)
		{
			numbers.push(input[i]);
		}

		for (auto op : operators)
		{
			temp1 = numbers.top();
			numbers.pop();
			temp2 = numbers.top();
			numbers.pop();

			switch (op)
			{
			case 0:
				numbers.push(temp1 + temp2);
				break;
			case 1:
				numbers.push(temp1 - temp2);
				break;
			case 2:
				numbers.push(temp1 * temp2);
				break;
			case 3:
				numbers.push(temp1 / temp2);
				break;
			}
		}

		answers.push_back(numbers.top());

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (operCount[i] > 0)
		{
			operCount[i]--;
			operators.push_back(i);
			func(input, operators);
			operators.pop_back();
			operCount[i]++;
		}
	}
}

int main()
{
	vector<int> input, operators;
	int temp;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		input.push_back(temp);
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> operCount[i];
	}

	func(input, operators);

	sort(answers.begin(), answers.end());

	cout << answers.back() << '\n' << answers.front() << '\n';

	return 0;
}