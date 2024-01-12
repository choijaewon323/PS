#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define IMPOSSIBLE 1000000000
#define MAX 100

int maxY, maxX;
char matrix[MAX][MAX];
int visited[MAX][MAX];

bool inRange(int y, int x) {
    if (0 <= y && y < maxY && 
        0 <= x && x < maxX) {
        return true;
    }
    return false;
}

bool stuck(int y, int x) {
    if (matrix[y][x] == 'D') {
        return true;
    }
    return false;
}

pair<int, int> move(int y, int x, int direction) {
    switch (direction) {
        case UP:
            while (true) {
                y--;
                if (!inRange(y, x)) {
                    y++;
                    break;
                }
                if (stuck(y, x)) {
                    y++;
                    break;
                }
            }
            break;
        case DOWN:
            while (true) {
                y++;
                if (!inRange(y, x)) {
                    y--;
                    break;
                }
                if (stuck(y, x)) {
                    y--;
                    break;
                }
            }
            break;
        case LEFT:
            while (true) {
                x--;
                if (!inRange(y, x)) {
                    x++;
                    break;
                }
                if (stuck(y, x)) {
                    x++;
                    break;
                }
            }
            break;
        case RIGHT:
            while (true) {
                x++;
                if (!inRange(y, x)) {
                    x--;
                    break;
                }
                if (stuck(y, x)) {
                    x--;
                    break;
                }
            }
            break;
    }
    
    return {y, x};
}

pair<int, int> findStart() {
    for (int y = 0; y < maxY; y++) {
        for (int x = 0; x < maxX; x++) {
            if (matrix[y][x] == 'R') {
                return {y, x};
            }
        }
    }
    
    return {-1, -1};
}

int solve(int y, int x, int cnt) {
    int result = IMPOSSIBLE;
    
    if (matrix[y][x] == 'G') {
        return cnt;
    }
    
    for (int i = 0; i < 4; i++) {
        pair<int, int> next = move(y, x, i);
        int ny = next.first;
        int nx = next.second;
        
        if (visited[ny][nx] > cnt + 1) {
            visited[ny][nx] = cnt + 1;
            result = min(result, solve(ny, nx, cnt + 1));
        }
    }
    
    return result;
}

void makeMatrix(vector<string>& board) {
    for (int y = 0; y < maxY; y++) {
        for (int x = 0; x < maxX; x++) {
            matrix[y][x] = board[y][x];
        }
    }
}

void initVisited() {
    for (int y = 0; y < maxY; y++) {
        for (int x = 0; x < maxX; x++) {
            visited[y][x] = IMPOSSIBLE;
        }
    }
}

int solution(vector<string> board) {
    int answer = 0;
    
    maxY = board.size();
    maxX = board[0].size();
    makeMatrix(board);
    
    initVisited();
    
    pair<int, int> start = findStart();
    
    answer = solve(start.first, start.second, 0);
    
    if (answer == IMPOSSIBLE) {
        return -1;
    }
    
    return answer;
}