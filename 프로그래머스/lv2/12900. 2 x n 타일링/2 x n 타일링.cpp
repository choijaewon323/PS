#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007

int dp[60001];

int solution(int n) {
    int answer = 0;
    
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] % MOD + dp[i - 2] % MOD) % MOD;
    }
    
    answer = dp[n];
    
    return answer;
}