#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100001];

int solution(vector<int> sticker)
{
    int answer = 0;
    
    int N = sticker.size();

    if (sticker.size() == 1) {
        return sticker[0];
    }
    
    dp[0] = sticker[0];
    dp[1] = sticker[0];
    
    // 0번 뜯음 - N-1번 못 뜯음
    for (int i = 2; i <= N - 2; i++) {
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
    }
    
    answer = max(answer, dp[N - 2]);
    
    // 0번 안뜯음 - N - 1 번 뜯을 수 있음
    dp[0] = 0;
    dp[1] = sticker[1];
    for (int i = 2; i <= N - 1; i++) {
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
    }
    answer = max(answer, dp[N - 1]);
    
    return answer;
}