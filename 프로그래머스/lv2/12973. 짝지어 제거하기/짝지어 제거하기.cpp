#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = -1;

    // base case
    if (s.size() == 1) {
        return 0;
    }
    
    stack<char> st;
    
    for (char c : s) {
        if (st.empty()) {
            st.push(c);
        }
        else {
            if (st.top() == c) {
                st.pop();
            }
            else {
                st.push(c);
            }
        }
    }
    
    if (st.empty()) {
        answer = 1;
    }
    else {
        answer = 0;
    }

    return answer;
}