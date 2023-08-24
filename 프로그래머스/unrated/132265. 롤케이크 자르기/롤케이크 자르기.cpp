#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    if (topping.size() == 1) {
        return 0;
    }
    
    map<int, int> left;
    map<int, int> right;
    
    int leftCnt = 0;
    int rightCnt = 0;
    
    for (int t : topping) {
        if (right[t] == 0) {
            rightCnt++;
        }
        right[t]++;
    }
    
    int half = 0;
    while (half < topping.size()) {
        
        int present = topping[half];
        
        // right에서 빼기
        right[present]--;
        
        if (right[present] == 0) {
            rightCnt--;
        }
        
        // left에 더하기
        if (left[present] == 0) {
            leftCnt++;
        }
        left[present]++;
        
        if (leftCnt == rightCnt) {
            answer++;
        }
        
        half++;
    }
    
    return answer;
}