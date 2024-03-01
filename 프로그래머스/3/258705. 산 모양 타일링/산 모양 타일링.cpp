#include <string>
#include <vector>

using namespace std;

/*
    한 변의 길이가 1인 정삼각형 2n + 1 개를 이어붙여
    윗변의 길이가 n, 아랫변의 길이가 n + 1 인 사다리꼴 만들 수 있음

    이때 n개의 윗정삼각형중 일부의 위쪽에 같은 크기의 정삼각형을 붙여
    새로운 모양 만듦

    이를 정삼각형 타일 또는 정삼각형 2개를 이어 붙인 마름모 타일로
    빈 곳이 없도록 채우려고 함
    둘다 돌려서 사용 가능

*/

#define MAX 100000
#define MOD 10007

int dp[MAX][2];

int solution(int n, vector<int> tops) {
    int answer = 0;

    if (tops[0] == 0) {
        dp[0][0] = 2;
        dp[0][1] = 1;
    }
    else {
        dp[0][0] = 3;
        dp[0][1] = 1;
    }

    for (int i = 1; i < tops.size(); i++) {
        int t = tops[i];

        if (t == 0) {
            dp[i][0] = dp[i - 1][0] * 2 + dp[i - 1][1] * 1;
            dp[i][1] = dp[i - 1][0] * 1 + dp[i - 1][1] * 1;
        }
        else {
            dp[i][0] = dp[i - 1][0] * 3 + dp[i - 1][1] * 2;
            dp[i][1] = dp[i - 1][0] * 1 + dp[i - 1][1] * 1;
        }

        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }

    answer = (dp[tops.size() - 1][0] + dp[tops.size() - 1][1]) % MOD;

    return answer;
}