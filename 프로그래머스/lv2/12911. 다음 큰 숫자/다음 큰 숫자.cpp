#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toBinary(int n) {
    string result = "";
    
    while (n > 0) {
        result += to_string(n % 2);
        n /= 2;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

int solution(int n) {
    int answer = 0;
    
    // 초기화
    string binaryN = toBinary(n);
    int cntOne = 0;
    
    for (char c : binaryN) {
        if (c == '1') {
            cntOne++;
        }
    }
    
    int temp = n;
    while (true) {
        temp++;
        int cnt = 0;
        
        string tempResult = toBinary(temp);
        
        for (char c : tempResult) {
            if (c == '1') {
                cnt++;
            }
        }
        
        if (cnt == cntOne) {
            answer = temp;
            break;
        }
    }
    
    return answer;
}