#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    
    for (auto temp : s)
    {
        if (temp == '(')
        {
            st.push(temp);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            else
            {
                if (st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    
    if (!st.empty())
    {
        return false;
    }

    return answer;
}