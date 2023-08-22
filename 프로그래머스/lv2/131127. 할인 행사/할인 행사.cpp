#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for (int i = 0; i < discount.size() - 9; i++) {
        map<string, int> cnt;
        
        // 1. 수량 측정
        for (int j = i; j < i + 10; j++) {
            string present = discount[j];
            
            cnt[present]++;
        }
        
        bool flag = true;
        // 2. want와 비교
        for (int j = 0; j < want.size(); j++) {
            string present = want[j];
            
            if (cnt[present] != number[j]) {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            answer++;
        }
    }
    
    return answer;
}