#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;
char tree[500];
vector<string> split(string &str, char delimiter)
{
	istringstream iss(str);
	string buffer;
	vector<string> result;
	while (getline(iss, buffer, delimiter))
	{
		result.push_back(buffer);
	}
	return result;
}
void inorder(vector<char> &result, int index)
{
	if (tree[index] == 0)
	{
		return;
	}
	inorder(result, index * 2);
	result.push_back(tree[index]);
	inorder(result, index * 2 + 1);
}
int main()
{
	int test_case;
	for (test_case = 1; test_case <= 10; test_case++)
	{
		int n;
		vector<char> result;
		for (int i = 0; i < 300; i++)
		{
			tree[i] = 0;
		}
		cin >> n;
		cin.ignore();
		for (int i = 0; i < n; i++)
		{
			string str;
			getline(cin, str);
			vector<string> splt = split(str, ' ');
			int index = stoi(splt[0]);
			char temp = splt[1][0];
			tree[index] = temp;
		}
		inorder(result, 1);
		int answer = 1;
		for (int i = 0; i < result.size(); i++)
		{
			if (i % 2 == 0)
			{
				if (result[i] > '9' || result[i] < '0')
				{
					answer = 0;
				}
			}
			else
			{
				if (result[i] >= '0' && result[i] <= '9')
				{
					answer = 0;
				}
			}
		}
		cout << "#" << test_case << " " << answer << '\n';
	}
	return 0;
}