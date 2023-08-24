#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

bool visited[100][100];

int N;
int M;

bool inRange(int y, int x) {
    if (0 <= y && y < N && 0 <= x && x < M) {
        return true;
    }
    return false;
}

char matrix[100][100];

int bfs(int startY, int startX) {
    queue<pair<int, int>> q;
    
    visited[startY][startX] = true;
    
    int result = matrix[startY][startX] - '0';
    
    q.push({startY, startX});
    
    while (!q.empty()) {
        pair<int, int> present = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int ny = present.first + dy[i];
            int nx = present.second + dx[i];
            
            if (inRange(ny, nx) && !visited[ny][nx] && matrix[ny][nx] != 'X') {
                visited[ny][nx] = true;
                q.push({ny, nx});
                result += matrix[ny][nx] - '0';
            }
        }
    }
    
    return result;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    N = maps.size();
    M = maps[0].size();
    
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            matrix[y][x] = maps[y][x];
        }
    }
    
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (!visited[y][x] && matrix[y][x] != 'X') {
                int result = bfs(y, x);
                
                answer.push_back(result);
            }
        }
    }
    
    if (answer.empty()) {
        answer.push_back(-1);
        
        return answer;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}