#include <string>
#include <vector>
using namespace std;

#define INF 1000000000
#define MAX 200

vector<vector<int>> matrix;
int dp[MAX + 1][MAX + 1];

int solve(int start, int end)
{
    if (start == end)
    {
        return 0;
    }
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    int result = INF;
    for (int i = start; i <= end - 1; i++)
    {
        result = min(result, solve(start, i) + solve(i + 1, end) + matrix[start][0] * matrix[i][1] * matrix[end][1]);
    }
    return dp[start][end] = result;
}

void init()
{
    for (int i = 0; i <= MAX; i++)
    {
        for (int j = 0; j <= MAX; j++)
        {
            dp[i][j] = -1;
        }
    }
}

int solution(vector<vector<int>> matrix_sizes) 
{
    init();
    matrix = matrix_sizes;
    int answer = solve(0, matrix.size() - 1);
    return answer;
}