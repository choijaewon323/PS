#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10
#define INF 1000000000

vector<vector<int>> target;
int maxRow;
int maxColumn;
int rowCount[MAX];
int columnCount[MAX];

bool isSame(vector<vector<int>> coins)
{
    for (int y = 0; y < maxRow; y++)
    {
        for (int x = 0; x < maxColumn; x++)
        {
            if (coins[y][x] != target[y][x])
            {
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> rowFlip(vector<vector<int>> coins, int y)
{
    vector<vector<int>> result = coins;
    for (int x = 0; x < maxColumn; x++)
    {
        if (coins[y][x] == 0)
        {
            result[y][x] = 1;
        }
        else
        {
            result[y][x] = 0;
        }
    }
    return result;
}

vector<vector<int>> columnFlip(vector<vector<int>> coins, int x)
{
    vector<vector<int>> result = coins;
    for (int y = 0; y < maxRow; y++)
    {
        if (coins[y][x] == 0)
        {
            result[y][x] = 1;
        }
        else
        {
            result[y][x] = 0;
        }
    }
    return result;
}

int solve(vector<vector<int>> coins, int prev)
{
    if (isSame(coins))
    {
        return 0;
    }
    // rowFlip
    int count = 0;
    int result = INF;
    for (int y = 0; y < maxRow; y++)
    {
        count++;
        if (rowCount[y] == 0 && count >= prev)
        {
            rowCount[y]++;
            vector<vector<int>> flip = rowFlip(coins, y);
            result = min(result, solve(flip, count) + 1);
            rowCount[y]--;
        }
    }
    
    // columnFlip
    for (int x = 0; x < maxColumn; x++)
    {
        count++;
        if (columnCount[x] == 0 && count >= prev)
        {
            columnCount[x]++;
            vector<vector<int>> flip = columnFlip(coins, x);
            result = min(result, solve(flip, count) + 1);
            columnCount[x]--;
        }
    }
    
    return result;
}

int solution(vector<vector<int>> beginning, vector<vector<int>> targ) {
    target = targ;
    maxRow = targ.size();
    maxColumn = targ[0].size();
    int answer = solve(beginning, -1);
    if (answer == INF)
    {
        return -1;
    }
    return answer;
}