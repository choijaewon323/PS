#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> alphabet;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;

	cin >> t;

	for (int test = 0; test < t; test++)
	{
		string w;
		int k;

		cin >> w;
		cin >> k;
		
		alphabet = vector<vector<int>>(26);
		int ans3 = INT32_MAX;
		int ans4 = -1;

		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < w.size(); j++)
			{
				if (w[j] == 'a' + i)
				{
					alphabet[i].push_back(j);
				}
			}

			if (alphabet[i].size() >= k)
			{
				int start = 0;
				int end = k - 1;

				while (end != alphabet[i].size())
				{
					int length = alphabet[i][end] - alphabet[i][start] + 1;

					ans3 = min(ans3, length);
					ans4 = max(ans4, length);

					start++;
					end++;
				}
			}
		}

		if (ans3 == INT32_MAX)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << ans3 << " " << ans4 << '\n';
		}
	}

	return 0;
}