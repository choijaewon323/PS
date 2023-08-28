#include <string>
#include <utility>
#include <map>
#include <vector>

using namespace std;

struct node {
    int startY;
    int startX;
    int endY;
    int endX;
};

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

bool inRange(int y, int x) {
    if (-5 <= y && y <= 5 && -5 <= x && x <= 5) {
        return true;
    }
    return false;
}

map<vector<int>, bool> visited;
 
int solution(string dirs) {
    int answer = 0;
    
    int y = 0;
    int x = 0;
    
    for (char d : dirs) {
        int ny;
        int nx;
        
        switch (d) {
            case 'U':
                ny = y + dy[UP];
                nx = x + dx[UP];
                break;
            case 'L':
                ny = y + dy[LEFT];
                nx = x + dx[LEFT];
                break;
            case 'D':
                ny = y + dy[DOWN];
                nx = x + dx[DOWN];
                break;
            case 'R':
                ny = y + dy[RIGHT];
                nx = x + dx[RIGHT];
        }
        
        if (inRange(ny, nx)) {
            vector<int> temp = {y, x, ny, nx};
            if (!visited[temp]) {
                answer++;
                visited[temp] = true;
                vector<int> rev = {ny, nx, y, x};
                visited[rev] = true;
            }
            
            y = ny;
            x = nx;
        }
    }
    
    return answer;
}