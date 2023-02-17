#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> words;
bool alphaUsed[26];
int wholeResult;
int n, k;

void func(int index, int count)
{
	if (count == k - 5)
	{
		int result = 0;
		bool correct;

		for (int i = 0; i < words.size(); i++)
		{
			correct = true;

			for (int j = 0; j < words[i].size(); j++)
			{
				if (!alphaUsed[words[i][j] - 'a'])
				{
					correct = false;
					break;
				}
			}

			if (correct)
			{
				result++;
			}
		}

		wholeResult = max(wholeResult, result);

		return;
	}

	for (int i = index; i < 26; i++)
	{
		if (alphaUsed[i])
		{
			continue;
		}
		alphaUsed[i] = true;
		func(i, count + 1);
		alphaUsed[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		string input;

		cin >> input;

		words.push_back(input);
	}

	if (k == 26)
	{
		cout << n << '\n';
		return 0;
	}

	if (k < 5)
	{
		cout << 0 << '\n';
		return 0;
	}

	alphaUsed['a' - 'a'] = true;
	alphaUsed['n' - 'a'] = true;
	alphaUsed['t' - 'a'] = true;
	alphaUsed['i' - 'a'] = true;
	alphaUsed['c' - 'a'] = true;

	func(0, 0);

	cout << wholeResult << '\n';

	return 0;
}