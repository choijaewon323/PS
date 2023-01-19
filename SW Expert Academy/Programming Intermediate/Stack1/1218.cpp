#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; test_case++)
	{
		stack<char> st;
		string brackets;
		int length;
		int result = 1;
		
		cin >> length;
		cin >> brackets;

		for (auto b : brackets)
		{
			if (b == '(' || b == '[' || b == '{' || b == '<')	// 여는 괄호일때
			{
				st.push(b);
			}
			else
			{
				if (st.empty())	// 스택이 비어있으면 pop할게 없음 -> 유효 X
				{
					result = 0;
					break;
				}
				else
				{
					char temp = st.top();

					if (b == ')' && temp == '(')	// () 일치
					{
						st.pop();
					}
					else if (b == ')' && temp != '(')	// () 불일치
					{
						result = 0;
						break;
					}

					if (b == ']' && temp == '[')	// [] 일치
					{
						st.pop();
					}
					else if (b == ']' && temp != '[')	// [] 불일치
					{
						result = 0;
						break;
					}

					if (b == '}' && temp == '{')	// {} 일치
					{
						st.pop();
					}
					else if (b == '}' && temp != '{')	// {} 불일치
					{
						result = 0;
						break;
					}

					if (b == '>' && temp == '<')	// <> 일치
					{
						st.pop();
					}
					else if (b == '>' && temp != '<')	// <> 불일치
					{
						result = 0;
						break;
					}
				}
			}
		}

		if (!st.empty())
		{
			result = 0;
		}

		cout << "#" << test_case << " " << result << '\n';
	}
}