#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

map<string, string> parent;
map<string, int> cnt;

string find(const string& x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return parent[x] = find(parent[x]);
	}
}

void union_find(string& f1, string& f2)
{
	string temp1, temp2;

	temp1 = find(f1);
	temp2 = find(f2);

	if (temp1 != temp2)
	{
		cnt[temp1] += cnt[temp2];
		parent[temp2] = temp1;
		cnt[temp2] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test;

	cin >> test;
	for (int i = 0; i < test; i++)
	{
		int f;

		cin >> f;
		
		parent.clear();
		cnt.clear();
		for (int j = 0; j < f; j++)
		{
			vector<string> input;
			string f1, f2;
			
			cin >> f1 >> f2;

			auto temp1 = parent.find(f1);
			auto temp2 = parent.find(f2);
			
			if (temp1 == parent.end())
			{
				parent[f1] = f1;
				cnt[f1] = 1;
			}

			if (temp2 == parent.end())
			{
				parent[f2] = f2;
				cnt[f2] = 1;
			}

			input.push_back(f1);
			input.push_back(f2);
			sort(input.begin(), input.end());

			union_find(input[0], input[1]);
			
			cout << cnt[find(f1)] << '\n';
		}
	}

	return 0;
}