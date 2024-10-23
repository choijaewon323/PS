#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 500

/*
    dp[i][j] : i번쨰 j 칸의 가능한 최댓값
    7
    3 8
    8 1 0
    2 7 4 4
    4 5 2 6 5
*/

int dp[MAX][MAX];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    dp[0][0] = triangle[0][0];
    
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) {   // left
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            } else {
                int tempMax = max(dp[i - 1][j], dp[i - 1][j - 1]);
                dp[i][j] = tempMax + triangle[i][j];
            }
        }
    }
    
    int bottom = triangle.size() - 1;
    for (int x = 0; x < triangle[bottom].size(); x++) {
        answer = max(answer, dp[bottom][x]);
    }
    
    return answer;
}