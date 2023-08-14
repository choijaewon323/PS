#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    sort(works.begin(), works.end(), greater<int>());
    
    int acc = 0;
    for (int i = 0; i < works.size(); i++) {
        acc += works[i];
    }
    
    if (acc <= n) {
        return 0;
    }
    
    while (n > 0) {
        int first = works.front();
        
        for (int i = 0; i < works.size(); i++) {
            if (works[i] == first) {
                works[i]--;
                n--;
                
                if (n == 0) {
                    break;
                }
            }
            else {
                break;
            }
        }
    }
    
    for (int i = 0; i < works.size(); i++) {
        answer += works[i] * works[i];
    }
    
    return answer;
}