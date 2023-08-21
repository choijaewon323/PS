#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toBinary(int num) {
    string result = "";
    
    if (num == 0) {
        return "0";
    }
    
    while (num > 0) {
        result += to_string(num % 2);
        num /= 2;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int removed = 0;
    int cnt = 0;
    while (true) {
        if (s == "1") {
            break;
        }
        
        // 1 routine
        string temp = "";
        for (char c : s) {
            if (c == '0') {
                removed++;
            }
            else {
                temp += '1';
            }
        }
        
        // 2 routine
        int num = temp.size();
        s = toBinary(num);
        
        cnt++;
    }
    
    answer.push_back(cnt);
    answer.push_back(removed);
    
    return answer;
}