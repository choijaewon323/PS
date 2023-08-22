#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool correct(string& str) {
    stack<char> st;
    
    for (char c : str) {
        if (st.empty()) {
            st.push(c);
        }
        else {
            if (c == '[' || c == '{' || c == '(') {
                st.push(c);
            }
            else {
                if (c == ']') {
                    if (st.top() != '[') {
                        return false;
                    }
                    else {
                        st.pop();
                    }
                }
                else if (c == '}') {
                    if (st.top() != '{') {
                        return false;
                    }
                    else {
                        st.pop();
                    }
                }
                else {
                    if (st.top() != '(') {
                        return false;
                    }
                    else {
                        st.pop();
                    }
                }
            }
        }
    }
    
    if (!st.empty()) {
        return false;
    }
    return true;
}

string roll(string& s, int dist) {
    string result = "";
    int size = s.size();
    
    for (int i = 0; i < size; i++) {
        int idx = (i + dist) % size;
        
        result += s[idx];
    }
    
    return result;
}

int solution(string s) {
    int answer = 0;
    
    for (int i = 0; i < s.size(); i++) {
        string temp = roll(s, i);
        
        if (correct(temp)) {
            answer++;
        }
    }
    
    return answer;
}