#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int test_case;

	for (test_case = 1; test_case <= 10; test_case++)
	{
		string cal;
		string output = "";
		stack<char> oper;
		stack<int64_t> postfix;
		int length;

		cin >> length;
		cin.ignore();
		cin >> cal;

		for (auto c : cal)
		{
			// 후위 표기식으로 변경
			if (c >= '0' && c <= '9')	// 숫자일 경우
			{
				output += c;
			}
			else	// 연산자일 경우 
			{
				if (oper.empty())
				{
					oper.push(c);
				}
				else if (c == '+')
				{
					while (!oper.empty())
					{
						char temp = oper.top();
						if (temp == '*')
						{
							oper.pop();
							output += temp;
						}
						else
						{
							oper.pop();
							output += temp;
							oper.push(c);
							break;
						}
					}
					if (oper.empty())
					{
						oper.push(c);
					}
				}
				else
				{
					while (!oper.empty())
					{
						char temp = oper.top();
						if (temp == '*')
						{
							oper.pop();
							output += temp;
							oper.push(c);
							break;
						}
						else
						{
							oper.push(c);
							break;
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

		for (auto o : output)
		{
			if (o >= '0' && o <= '9')
			{
				int temp = o - '0';
				postfix.push((int64_t)temp);
			}
			else if (o == '*')
			{
				int64_t temp2 = postfix.top();
				postfix.pop();
				int64_t temp1 = postfix.top();
				postfix.pop();
				postfix.push(temp1 * temp2);
			}
			else
			{
				int64_t temp2 = postfix.top();
				postfix.pop();
				int64_t temp1 = postfix.top();
				postfix.pop();
				postfix.push(temp1 + temp2);
			}
		}

		cout << "#" << test_case << " " << postfix.top() << '\n';
	}

	return 0;
}