#include <iostream>
#include <string>
#include <stack>
using namespace std;

int priority(char c)
{
	if (c == '*')
	{
		return 2;
	}
	else if (c == '+')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int test_case;

	for (test_case = 1; test_case <= 10; test_case++)
	{
		string input;
		string output = "";
		stack<char> oper;
		stack<int> postfix;
		int length;

		cin >> length;
		cin.ignore();
		cin >> input;

		for (auto c : input)
		{
			if (c >= '0' && c <= '9')	// 피연산자일 경우
			{
				output += c;
			}
			else if (c == '(' || c == ')')	// 괄호일 경우
			{
				if (c == '(')	// 여는 괄호일 경우
				{
					oper.push(c);
				}
				else	// 닫는 괄호일 경우
				{
					while (!oper.empty())
					{
						char temp = oper.top();

						if (temp == '(')
						{
							oper.pop();
							break;
						}
						else
						{
							oper.pop();
							output += temp;
						}
					}
				}
			}
			else	// 연산자일 경우
			{
				if (oper.empty())
				{
					oper.push(c);
				}
				else
				{
					while (!oper.empty())
					{
						char temp = oper.top();

						if (priority(c) > priority(temp))
						{
							oper.push(c);
							break;
						}
						else
						{
							oper.pop();
							output += temp;
						}
					}
					if (oper.empty())
					{
						oper.push(c);
					}
				}
			}
		}

		while (!oper.empty())
		{
			char temp = oper.top();
			oper.pop();
			output += temp;
		}

		for (auto c : output)
		{
			if (c >= '0' && c <= '9')
			{
				postfix.push(c - '0');
			}
			else
			{
				int temp2 = postfix.top();
				postfix.pop();
				int temp1 = postfix.top();
				postfix.pop();

				if (c == '*')
				{
					postfix.push(temp1 * temp2);
				}
				else
				{
					postfix.push(temp1 + temp2);
				}
			}
		}
		cout << "#" << test_case << " " << postfix.top() << '\n';
	}

	return 0;
}