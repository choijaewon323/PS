#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string& a, string& b) {
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end(), compare);
    
    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = i; j < phone_book.size(); j++) {
            if (i == j) {
                continue;
            }
            bool flag = true;
            
            for (int k = 0; k < phone_book[i].size(); k++) {
                if (phone_book[i][k] != phone_book[j][k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return false;
            }
        }
    }
    
    return answer;
}