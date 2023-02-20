#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> numbers;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;

		cin >> temp;
		numbers.push_back(temp);
	}
}

void solution()
{
	// 음수면 false, 양수면 true
	bool all, isAllSame;
	int frnt = numbers.front();

	if (frnt < 0)
	{
		all = false;
	}
	else
	{
		all = true;
	}

	isAllSame = true;
	for (int i = 1; i < numbers.size(); i++)
	{
		if (all == false && numbers[i] > 0)
		{
			isAllSame = false;
			break;
		}
		if (all == true && numbers[i] < 0)
		{
			isAllSame = false;
			break;
		}
	}

	if (isAllSame)
	{
		if (all == false)
		{
			cout << numbers[numbers.size() - 2] << " "
				<< numbers[numbers.size() - 1] << '\n';
		}
		else
		{
			cout << numbers[0] << " "
				<< numbers[1] << '\n';
		}
	}
	else
	{
		vector<int> answers(2);
		int minTemp = 2000000000;

		for (int i = 0; i < numbers.size(); i++)
		{
			int present = numbers[i];
			int index;
			
			auto search = lower_bound(numbers.begin(), numbers.end(), -present);

			if (search == numbers.end())
			{
				index = numbers.size() - 1;
			}
			else
			{
				index = search - numbers.begin();
			}
			int answer = present + numbers[index];
			int answer2;
			if (index != 0)
			{
				answer2 = present + numbers[index - 1];
			}
			else
			{
				answer2 = present + numbers[0];
			}

			if (i != index && abs(answer) < minTemp)
			{
				minTemp = abs(answer);
				answers[0] = present;
				answers[1] = numbers[index];
			}
			if (i != index - 1 && abs(answer2) < minTemp)
			{
				minTemp = abs(answer2);
				answers[0] = present;
				answers[1] = numbers[index - 1];
			}
		}

		sort(answers.begin(), answers.end());

		cout << answers[0] << " " << answers[1] << '\n';
	}
}

int main()
{
	input();
	solution();

	return 0;
}