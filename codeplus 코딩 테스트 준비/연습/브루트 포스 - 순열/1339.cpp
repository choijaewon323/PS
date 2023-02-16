#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<char, int>> alphaNum;
vector<string> words;

int power(int a, int n)
{
	if (n == 0)
	{
		return 1;
	}
	return a * power(a, n - 1);
}

bool compare(pair<char, int> &a, pair<char, int> &b)
{
	return a.second > b.second;
}

int main()
{
	for (int i = 0; i < 26; i++)
	{
		alphaNum.push_back(make_pair('A' + i, 0));
	}

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string temp;

		cin >> temp;

		for (int index = 0; index < temp.size(); index++)
		{
			for (auto &a : alphaNum)
			{
				if (a.first == temp[index])
				{
					a.second += power(10, temp.size() - index - 1);
					break;
				}
			}
		}

		words.push_back(temp);
	}

	sort(alphaNum.begin(), alphaNum.end(), compare);

	int count = 9;
	for (auto &a : alphaNum)
	{
		if (a.second == 0)
		{
			continue;
		}
		a.second = count;
		count--;
	}

	int acc = 0;
	for (auto w : words)
	{
		int temp = 0;
		for (int i = 0; i < w.size(); i++)
		{
			for (auto a : alphaNum)
			{
				if (w[i] == a.first)
				{
					temp += a.second * power(10, w.size() - i - 1);
					break;
				}
			}
		}
		acc += temp;
	}

	cout << acc << '\n';

	return 0;
}