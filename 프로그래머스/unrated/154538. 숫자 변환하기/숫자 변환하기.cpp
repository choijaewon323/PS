#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000001];

int solution(int x, int y, int n) {
    int answer = 0;
    
    // base case
    if (x == y) {
        return 0;
    }
    
    // init
    for (int i = 1; i <= 1000000; i++) {
        dp[i] = -1;
    }
    
    dp[x] = 0;
    
    for (int i = x; i <= y - 1; i++) {
        if (dp[i] != -1) {
            if (i + n <= y) {
                if (dp[i + n] == -1) {
                    dp[i + n] = dp[i] + 1;
                }
                else {
                    dp[i + n] = min(dp[i + n], dp[i] + 1);
                }
            }
            if (i * 2 <= y) {
                if (dp[i * 2] == -1) {
                    dp[i * 2] = dp[i] + 1;
                }
                else {
                    dp[i * 2] = min(dp[i * 2], dp[i] + 1);
                }
            }
            if (i * 3 <= y) {
                if (dp[i * 3] == -1) {
                    dp[i * 3] = dp[i] + 1;
                }
                else {
                    dp[i * 3] = min(dp[i * 3], dp[i] + 1);
                }
            }
        }
    }
    
    answer = dp[y];
    
    return answer;
}