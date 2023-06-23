#include <string>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

vector<int> solution(vector<int> prices) 
{       
    int size = prices.size();
    vector<int> answer(size);
    stack<pair<int, int>> st;
    
    for (int i = 0; i < size; i++)
    {
        if (st.empty())
        {
            st.push(make_pair(i, prices[i]));
        }
        else
        {
            if (st.top().second <= prices[i])
            {
                st.push(make_pair(i, prices[i]));
            }
            else
            {
                while (!st.empty() && st.top().second > prices[i])
                {
                    pair<int, int> temp = st.top();
                    st.pop();

                    answer[temp.first] = i - temp.first;
                }
                st.push(make_pair(i, prices[i]));
            }
        }
    }
    
    while (!st.empty())
    {
        pair<int, int> temp = st.top();
        st.pop();
        
        answer[temp.first] = size - 1 - temp.first;
    }
    
    return answer;
}