#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int result;
vector<bool> visited;

void func(vector<vector<int>>& dungeons, int k, int cnt)
{
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!visited[i] && dungeons[i][0] <= k)
        {
            visited[i] = true;
            func(dungeons, k - dungeons[i][1], cnt + 1);
            visited[i] = false;
        }
    }
    
    result = max(cnt, result);
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    visited = vector<bool>(dungeons.size(), false);
    
    func(dungeons, k, 0);
    
    answer = result;
    
    return answer;
}