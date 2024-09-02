#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>
using namespace std;

#define MAX 4
#define EMPTY 0
#define RED 1
#define BLUE 2
#define RED_END 3
#define BLUE_END 4
#define WALL 5

int N, M;
int maze[MAX][MAX];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

struct Node {
    vector<vector<bool>> redVisited;
    vector<vector<bool>> blueVisited;
    pair<int, int> red;
    pair<int, int> blue;
    int turn;
};

void init(vector<vector<int>>& m) {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            maze[y][x] = m[y][x];
        }
    }
}

pair<int, int> findRedStart() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (maze[y][x] == RED) {
                return {y, x};
            }
        }
    }
    return {-1, -1};
}

pair<int, int> findBlueStart() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (maze[y][x] == BLUE) {
                return {y, x};
            }
        }
    }
    return {-1, -1};
}

bool inRange(int y, int x) {
    return (0 <= y && y < N && 0 <= x && x < M);
}

bool isWall(int y, int x) {
    return (maze[y][x] == WALL);
}

bool isRedEnd(int y, int x) {
    return (maze[y][x] == RED_END);
}

bool isBlueEnd(int y, int x) {
    return (maze[y][x] == BLUE_END);
}

bool isAllEnd(pair<int, int>& red, pair<int, int>& blue) {
    return (maze[red.first][red.second] == RED_END && 
            maze[blue.first][blue.second] == BLUE_END);
}

void blueMove(queue<Node>& q, Node present) {
    pair<int, int> blue = present.blue;
    
    for (int i = 0; i < 4; i++) {
        int ny = blue.first + dy[i];
        int nx = blue.second + dx[i];
        vector<vector<bool>> blueVisited = present.blueVisited;
        
        if (inRange(ny, nx) && !isWall(ny, nx) && !isRedEnd(ny, nx) && !blueVisited[ny][nx]) {
            blueVisited[ny][nx] = true;
            q.push({present.redVisited, blueVisited, present.red, {ny, nx}, present.turn + 1});
        }
    }
}

void redMove(queue<Node>& q, Node present) {
    pair<int, int> red = present.red;
    
    for (int i = 0; i < 4; i++) {
        int ny = red.first + dy[i];
        int nx = red.second + dx[i];
        vector<vector<bool>> redVisited = present.redVisited;
        
        if (inRange(ny, nx) && !isWall(ny, nx) && !isBlueEnd(ny, nx) && !redVisited[ny][nx]) {
            redVisited[ny][nx] = true;
            q.push({redVisited, present.blueVisited, {ny, nx}, present.blue, present.turn + 1});
        }
    }
}

void blueFirst(queue<Node>& q, Node present) {
    pair<int, int> blue = present.blue;
    pair<int, int> red = present.red;
    
    for (int i = 0; i < 4; i++) {
        int ny = blue.first + dy[i];
        int nx = blue.second + dx[i];
        vector<vector<bool>> blueVisited = present.blueVisited;
        
        if (inRange(ny, nx) &&
           !isWall(ny, nx) &&
           !blueVisited[ny][nx] &&
           !(red.first == ny && red.second == nx)) {
            
            for (int j = 0; j < 4; j++) {
                int zy = red.first + dy[j];
                int zx = red.second + dx[j];
                vector<vector<bool>> redVisited = present.redVisited;
                
                if (inRange(zy, zx) &&
                   !isWall(zy, zx) &&
                   !redVisited[zy][zx] &&
                   !(ny == zy && nx == zx)) {
                    blueVisited[ny][nx] = true;
                    redVisited[zy][zx] = true;
                    q.push({redVisited, blueVisited, {zy, zx}, {ny, nx}, present.turn + 1});
                }
            }
        }
    }
}

void redFirst(queue<Node>& q, Node present) {
    pair<int, int> blue = present.blue;
    pair<int, int> red = present.red;
    
    for (int i = 0; i < 4; i++) {
        int ny = red.first + dy[i];
        int nx = red.second + dx[i];
        vector<vector<bool>> redVisited = present.redVisited;
        
        if (inRange(ny, nx) &&
           !isWall(ny, nx) &&
           !redVisited[ny][nx] &&
           !(blue.first == ny && blue.second == nx)) {
            
            for (int j = 0; j < 4; j++) {
                int zy = blue.first + dy[j];
                int zx = blue.second + dx[j];
                vector<vector<bool>> blueVisited = present.blueVisited;
                
                if (inRange(zy, zx) &&
                   !isWall(zy, zx) &&
                   !blueVisited[zy][zx] &&
                   !(ny == zy && nx == zx)) {
                    redVisited[ny][nx] = true;
                    blueVisited[zy][zx] = true;
                    q.push({redVisited, blueVisited, {ny, nx}, {zy, zx}, present.turn + 1});
                }
            }
        }
    }
}

int bfs() {
    vector<vector<bool>> redVisited(N, vector<bool>(M, false));
    vector<vector<bool>> blueVisited(N, vector<bool>(M, false));
    pair<int, int> redStart = findRedStart();
    pair<int, int> blueStart = findBlueStart();
    
    redVisited[redStart.first][redStart.second] = true;
    blueVisited[blueStart.first][blueStart.second] = true;
    
    queue<Node> q;
    q.push({redVisited, blueVisited, redStart, blueStart, 0});
    
    while (!q.empty()) {
        Node present = q.front();
        q.pop();
        
        if (isAllEnd(present.red, present.blue)) {
            return present.turn;
        }
        
        if (isRedEnd(present.red.first, present.red.second)) {
            blueMove(q, present);
        }
        else if (isBlueEnd(present.blue.first, present.blue.second)) {
            redMove(q, present);
        }
        else {  // nobody end
            blueFirst(q, present);
            redFirst(q, present);
        }
    }
    
    return 0;
}

int solution(vector<vector<int>> m) {
    N = m.size();
    M = m[0].size();
    
    init(m);
    return bfs();
}