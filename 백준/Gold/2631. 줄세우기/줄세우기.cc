#include <iostream>
#include <algorithm>
using namespace std;

/*
    구해야 하는 것 : 번호 순서대로 배치하기 위해 옮겨지는 아이의 최소 수

    전체 길이 - 가장 길게 증가하는 수열(LIS)
    3, 4, 5 6 은 잘 서있음
    7, 1 2 가 제대로 안 서있음

    
*/

#define MAX 200

int input[MAX];
int dp[MAX];
int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }

    for (int i = 0; i < N; i++) {
        
        int lessThanPresent = 0;

        for (int j = 0; j < i; j++) {
            if (input[j] < input[i]) {
                lessThanPresent = max(lessThanPresent, dp[j]);
            }
        }

        dp[i] = lessThanPresent + 1;
    }

    int maxVal = 0;

    for (int i = 0; i < N; i++) {
        maxVal = max(maxVal, dp[i]);
    }

    cout << N - maxVal << '\n';

    return 0;
}