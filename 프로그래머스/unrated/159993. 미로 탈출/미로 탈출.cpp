#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

char maze[100][100];
vector<vector<int>> visited;

int N,M;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

bool inRange(int y, int x) {
    if (0 <= y && y < N && 0 <= x && x < M) {
        return true;
    }
    return false;
}

int bfsLever(int startY, int startX, int leverY, int leverX) {
    visited = vector<vector<int>>(N, vector<int>(M, 0));
    queue<pair<int, int>> q;
    
    visited[startY][startX] = 1;
    q.push({startY, startX});
    
    while (!q.empty()) {
        pair<int, int> present = q.front();
        q.pop();
        
        if (present.first == leverY && present.second == leverX) {
            return visited[leverY][leverX] - 1;
        }
        
        for (int i = 0; i < 4; i++) {
            int ny = present.first + dy[i];
            int nx = present.second + dx[i];
            
            if (inRange(ny, nx) && visited[ny][nx] == 0 && maze[ny][nx] != 'X') {
                visited[ny][nx] = visited[present.first][present.second] + 1;
                q.push({ny, nx});
            }
        }
    }
    
    return -1;
}

int bfsEnd(int startY, int startX, int endY, int endX) {
    visited = vector<vector<int>>(N, vector<int>(M, 0));
    queue<pair<int, int>> q;
    
    visited[startY][startX] = 1;
    q.push({startY, startX});
    
    while (!q.empty()) {
        pair<int, int> present = q.front();
        q.pop();
        
        if (present.first == endY && present.second == endX) {
            return visited[endY][endX] - 1;
        }
        
        for (int i = 0; i < 4; i++) {
            int ny = present.first + dy[i];
            int nx = present.second + dx[i];
            
            if (inRange(ny, nx) && visited[ny][nx] == 0 && maze[ny][nx] != 'X') {
                visited[ny][nx] = visited[present.first][present.second] + 1;
                q.push({ny, nx});
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    N = maps.size();
    M = maps[0].size();
    
    int startY, startX, endY, endX, leverY, leverX;
    
    for (int y = 0; y < N; y++) {
        string temp = maps[y];
        for (int x = 0; x < M; x++) {
            maze[y][x] = temp[x];
            
            if (temp[x] == 'S') {
                startY = y;
                startX = x;
            }
            
            if (temp[x] == 'E') {
                endY = y;
                endX = x;
            }
            
            if (temp[x] == 'L') {
                leverY = y;
                leverX = x;
            }
        }
    }
    
    // start to lever
    int result1 = bfsLever(startY, startX, leverY, leverX);
    
    if (result1 == -1) {
        return -1;
    }
    answer += result1;
    
    int result2 = bfsEnd(leverY, leverX, endY, endX);
    
    if (result2 == -1) {
        return -1;
    }
    answer += result2;
    
    return answer;
}