#include <string>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

vector<int> solution(vector<int> prices) {
    const int size = prices.size();
    vector<int> answer(size, 0);
    
    stack<pair<int, int>> st;
    
    for (int i = 0; i < size; i++) {
        int present = prices[i];
        
        if (st.empty()) {
            st.push({i, present});
        } else {
            pair<int, int> tp = st.top();
            
            if (tp.second <= present) {
                st.push({i, present});
            } else {
                while (!st.empty() && st.top().second > present) {
                    pair<int, int> temp = st.top();
                    st.pop();
                    
                    answer[temp.first] = i - temp.first;
                }
                
                st.push({i, present});
            }
        }
    }
    
    while (!st.empty()) {
        pair<int, int> temp = st.top();
        st.pop();
        
        answer[temp.first] = (size - 1) - temp.first;
    }
    
    return answer;
}