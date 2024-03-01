#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define INF 1000000000
#define MAX 100000

vector<int> scores = {
                        1,2,3,4,5,6,7,8,9,10,11,12,13,14,
                        15,16,17,18,19,20,21,
                        22,24,26,27,28,30,32,33,34,36,38,
                        39,40,42,45,48,50,51,54,57,60
                     };
pair<int, int> dp[MAX + 300];

bool singleOrBool(int dart)
{
    if ((1 <= dart && dart <= 20) || dart == 50)
    {
        return true;
    }
    return false;
}

vector<int> solve(int target, int cnt, int sobCnt)
{
    if (target == 0)
    {
        vector<int> answer = {cnt, sobCnt};
        return answer;
    }
    for (int score : scores)
    {
        if (target >= score)
        {
            if (singleOrBool(score))
            {
                return solve(target - score, cnt + 1, sobCnt + 1);
            }
            else
            {
                return solve(target - score, cnt + 1, sobCnt);   
            }
        }
    }
    return vector<int>();
}

void init()
{
    for (int i = 0; i < MAX + 300; i++)
    {
        dp[i] = {INF, INF};
    }
}

vector<int> solution(int target) 
{
    init();
    dp[0] = {0, 0};
    for (int i = 0; i <= target; i++)
    {
        int presentDart = dp[i].first;
        int presentSob = dp[i].second;
        for (int score : scores)
        {
            int nextDart = presentDart + 1;
            int nextSob = presentSob;
            if (singleOrBool(score))
            {
                nextSob++;
            }
            if (dp[i + score].first > nextDart)
            {
                dp[i + score] = {nextDart, nextSob};
            }
            else if (dp[i + score].first == nextDart && dp[i + score].second < nextSob)
            {
                dp[i + score] = {nextDart, nextSob};
            }
        }
    }
    vector<int> answer = {dp[target].first, dp[target].second};
    return answer;
}