/*
    괄호 짝을 맞춰야함
    
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrect(string str) {
    stack<char> st;
    
    int strSize = str.size();
    for (int i = 0; i < strSize; i++) {
        char c = str[i];
        
        if (st.empty()) {
            if (c == '(') {
                st.push(c);
            }
            else {
                return false;
            }
        }
        else {
            if (c == '(') {
                st.push(c);
            }
            else {
                if (st.top() == '(') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
    }
    
    if (!st.empty()) {
        return false;
    }
    return true;
}

string solve(string str) {
    // 1
    if (str.empty()) {
        return "";
    }
    
    // 2
    int acc;
    
    if (str[0] == '(') {
        acc = 1;
    }
    else {
        acc = -1;
    }
    
    int index;
    int strSize = str.size();
    for (int i = 1; i < strSize; i++) {
        if (str[i] == '(') {
            acc++;
        }
        else {
            acc--;
        }
        
        if (acc == 0) {
            // logic
            index = i;
            break;
        }
    }
    
    string str1 = str.substr(0, index + 1);
    string str2 = "";
    if (index + 1 < strSize) {
        str2 = str.substr(index + 1);   
    }
    
    bool correct1 = isCorrect(str1);
    
    // 3, 3-1
    if (correct1) {
        return str1 + solve(str2);
    }
    
    // 4
    string result = "(";
    
    result += solve(str2);
    
    result += ')';
    
    string temp = "";
    
    int str1Size = str1.size();
    for (int i = 1; i < str1Size - 1; i++) {
        if (str1[i] == '(') {
            temp += ')';
        }
        else {
            temp += '(';
        }
    }
    
    result += temp;
    
    return result;
}

string solution(string p) {
    string answer = "";
    
    if (isCorrect(p)) {
        return p;
    }
    
    answer = solve(p);
    
    return answer;
}