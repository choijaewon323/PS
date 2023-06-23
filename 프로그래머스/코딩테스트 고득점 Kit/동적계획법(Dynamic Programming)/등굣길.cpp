#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int matrix[101][101];
int dp[101][101];

int dy[] = {0, 1};
int dx[] = {1, 0};

int maxM;
int maxN;

bool inRange(int y, int x)
{
    if (y >= 1 && y <= maxM && x >= 1 && x <= maxN)
    {
        return true;
    }
    return false;
}

int func(int y, int x)
{   
    if (matrix[y][x] == 1)
    {
        return 0;
    }
    
    if (y == maxM && x == maxN)
    {
        return 1;
    }
    
    if (dp[y][x] != -1)
    {
        return dp[y][x];   
    }
    
    int result = 0;
    for (int i = 0; i < 2; i++)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        
        if (inRange(nextY, nextX))
        {
            result += func(nextY, nextX);
            result %= 1000000007;
        }
    }
    
    return dp[y][x] = result;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    maxM = n;
    maxN = m;
    
    for (int i =0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            dp[i][j] = -1;
        }
    }
    
    for (auto p : puddles)
    {
        matrix[p[1]][p[0]] = 1;
    }
    
    answer = func(1, 1);
    answer %= 1000000007;
    
    return answer;
}