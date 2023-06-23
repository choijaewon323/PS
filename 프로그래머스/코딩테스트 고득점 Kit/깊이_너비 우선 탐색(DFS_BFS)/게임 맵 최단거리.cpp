#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

bool inRange(int y, int x, int n, int m)
{
    if (y >= 0 && y < n && x >= 0 && x < m)
    {
        return true;
    }
    return false;
}

int bfs(int startY, int startX, vector<vector<int>>& maps)
{
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    
    visited[startY][startX] = 1;
    q.push(make_pair(startY, startX));
    
    while (!q.empty()) 
    {
        pair<int, int> temp = q.front();
        q.pop();
        
        if (temp.first == n - 1 && temp.second == m - 1)
        {
            return visited[temp.first][temp.second] + 1;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int nextY = temp.first + dy[i];
            int nextX = temp.second + dx[i];
            
            if (inRange(nextY, nextX, n, m) && visited[nextY][nextX] == 0 &&
               maps[nextY][nextX] == 1)
            {
                visited[nextY][nextX] = visited[temp.first][temp.second] + 1;
                q.push(make_pair(nextY, nextX));
            }
        }
    }
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    answer = bfs(0, 0, maps);
    
    if (answer > 0)
    {
        answer--;
    }
    
    return answer;
}