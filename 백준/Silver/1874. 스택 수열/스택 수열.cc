#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> seq;
vector<char> answer;
int n;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		
		seq.push_back(temp);
	}
}

bool solve()
{
	int seqIndex = 0;
	stack<int> st;

	for (int num = 1; num <= n; num++)
	{
		if (seq[seqIndex] >= num)
		{
			st.push(num);
			answer.push_back('+');
		}
		else
		{
			if (st.empty())
			{
				return false;
			}

			if (st.top() == seq[seqIndex])
			{
				st.pop();
				num--;
				answer.push_back('-');
				seqIndex++;
			}
			else
			{
				return false;
			}
		}
	}

	const int seqSize = seq.size();
	while (seqIndex < seqSize && !st.empty())
	{
		if (st.top() == seq[seqIndex])
		{
			st.pop();
			answer.push_back('-');
			seqIndex++;
		}
		else
		{
			return false;
		}
	}

	return true;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	if (solve())
	{
		// do something
		for (char c : answer)
		{
			cout << c << '\n';
		}
	}
	else
	{
		cout << "NO" << '\n';
	}

	return 0;
}