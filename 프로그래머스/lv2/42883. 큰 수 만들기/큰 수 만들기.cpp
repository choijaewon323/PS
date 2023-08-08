#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    stack<char> st;
    
    for (char n : number) {
        while (!st.empty() && st.top() < n && k > 0) {
            st.pop();
            k--;
        }
        st.push(n);
    }
    
    if (k > 0) {
        for (int i = 0; i < k; i++) {
            st.pop();
        }
    }
    
    int size = st.size();
    for (int i = 0; i < size; i++) {
        answer += st.top();
        st.pop();
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}