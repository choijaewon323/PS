#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    
    for (auto a : arr)
    {
        if (st.empty())
        {
            answer.push_back(a);
            st.push(a);
            continue;
        }
        if (st.top() == a)
        {
            continue;
        }
        if (st.top() != a)
        {
            answer.push_back(a);
            st.push(a);
        }
    }

    return answer;
}