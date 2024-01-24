#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

string full;
string explosion;

void input() 
{
	cin >> full;
	cin >> explosion;
}

string solve()
{
	stack<pair<char, int>> st;

	const int fullSize = full.size();
	const int expSize = explosion.size();

	for (int i = 0; i < fullSize; i++)
	{
		const char present = full[i];

		if (st.empty())
		{
			if (present == explosion[0])
			{
				st.push({ present, 1 });
			}
			else
			{
				st.push({ present, -1 });
			}
		}
		else
		{
			const int index = st.top().second;
			if (index != -1 && present == explosion[index])
			{
				st.push({ present, index + 1 });
			}
			else
			{
				if (present == explosion[0])
				{
					st.push({ present, 1 });
				}
				else
				{
					st.push({ present, -1 });
				}
			}
		}

		if (!st.empty() && st.top().second == expSize)
		{
			for (int j = 0; j < expSize; j++)
			{
				st.pop();
			}
		}
	}

	if (st.empty())
	{
		return "FRULA";
	}
	
	string result = "";
	while (!st.empty())
	{
		result += st.top().first;
		st.pop();
	}
	reverse(result.begin(), result.end());

	return result;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	
	cout << solve() << '\n';

	return 0;
}