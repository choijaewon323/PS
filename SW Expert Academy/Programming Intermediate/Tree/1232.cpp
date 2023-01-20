#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#define NUM 0
#define OPER 1

typedef struct _node
{
	int type;
	long double data;
	char oper;
	int left;
	int right;
} node;

node tree[5000];

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

long double expression(int index)
{
	if (tree[index].type == NUM)
	{
		return tree[index].data;
	}

	long double op1 = expression(tree[index].left);
	long double op2 = expression(tree[index].right);
	char oper = tree[index].oper;

	if (oper == '+')
	{
		return op1 + op2;
	}
	else if (oper == '-')
	{
		return op1 - op2;
	}
	else if (oper == '*')
	{
		return op1 * op2;
	}
	else if (oper == '/')
	{
		return op1 / op2;
	}

	return 0;
}

int main()
{
	int test_case;
	
	for (test_case = 1; test_case <= 10; test_case++)
	{
		int n;
		cin >> n;

		cin.ignore();
		for (int i = 1; i <= n; i++)
		{
			vector<string> tempResult;
			string str;
			char temp;

			getline(cin, str);
			tempResult = split(str, ' ');
			temp = tempResult[1][0];

			if (temp >= '0' && temp <= '9')
			{
				tree[i].data = stoi(tempResult[1]);
				tree[i].type = NUM;
			}
			else
			{
				tree[i].oper = temp;
				tree[i].type = OPER;
				tree[i].left = stoi(tempResult[2]);
				tree[i].right = stoi(tempResult[3]);
			}
		}

		cout << "#" << test_case << " " << (int)expression(1) << '\n';
	}

	return 0;
}