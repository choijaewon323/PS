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
		stack<int> postfix;
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
				else
				{
					char temp = oper.top();
					oper.pop();
					output += temp;
					oper.push(c);
				}
			}
		}
		output += oper.top();
		oper.pop();
		
		reverse(output.begin(), output.end());

		for (auto c : output)
		{
			if (c == '+')
			{
				postfix.push(-1);
			}
			else
			{
				postfix.push(c - '0');
			}
		}
		
		while (1)
		{
			int temp2 = postfix.top();
			postfix.pop();
			int temp1 = postfix.top();
			postfix.pop();
			postfix.pop();
			postfix.push(temp1 + temp2);

			if (postfix.size() == 1)
			{
				break;
			}
		}

		cout << "#" << test_case << " " << postfix.top() << '\n';
	}

	return 0;
}