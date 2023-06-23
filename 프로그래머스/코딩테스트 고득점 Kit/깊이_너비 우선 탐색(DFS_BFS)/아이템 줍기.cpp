#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int matrix[102][102];
int visited[102][102];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

bool inRange(int y, int x)
{
    if (y >= 0 && y <= 101 && x >= 0 && x <= 101)
    {
        return true;
    }
    return false;
}

int bfs(int startX, int startY, int endX, int endY)
{
    queue<pair<int, int>> q;
    visited[startY][startX] = 1;
    q.push(make_pair(startY, startX));
    
    while (!q.empty())
    {
        int presentY = q.front().first;
        int presentX = q.front().second;
        q.pop();
        
        if (presentY == endY && presentX == endX)
        {
            return visited[presentY][presentX] - 1;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int nextY = presentY + dy[i];
            int nextX = presentX + dx[i];
            
            if (inRange(nextY, nextX) && visited[nextY][nextX] == 0 && matrix[nextY][nextX] == 1)
            {
                visited[nextY][nextX] = visited[presentY][presentX] + 1;
                q.push(make_pair(nextY, nextX));
            }
        }
    }
    
    return -1;
}


void makeLine(int startX, int startY, int endX, int endY)
{
    for (int y = startY; y <= endY; y++)
    {
        for (int x = startX; x <= endX; x++)
        {
            matrix[y][x] = 1;
        }
    }
}

void deleteInside(int startX, int startY, int endX, int endY)
{
    for (int y = startY + 1; y <= endY - 1; y++)
    {
        for (int x = startX + 1; x <= endX - 1; x++)
        {
            matrix[y][x] = 0;
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    for (auto r : rectangle)
    {
        makeLine(r[0] * 2, r[1] * 2, r[2] * 2, r[3] * 2);
    }
    
    for (auto r : rectangle)
    {
        deleteInside(r[0] * 2, r[1] * 2, r[2] * 2, r[3] * 2);
    }
    
    answer = bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    
    return answer / 2;
}