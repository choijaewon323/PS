#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if (n > s) {
        answer.push_back(-1);
        
        return answer;
    }
    
    int div = s / n;

    for (int i = 1; i <= n; i++) {
        answer.push_back(div);
    }
    
    int rest = s % n;
    
    for (int i = 0; i < rest; i++) {
        answer[i]++;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}