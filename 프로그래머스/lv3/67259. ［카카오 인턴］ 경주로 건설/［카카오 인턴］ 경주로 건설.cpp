#include <string>
#include <vector>
#include <queue>

using namespace std;

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

#define INF 100000000

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int N;

int cost[25][25];

void init() {
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 25; x++) {
            cost[y][x] = INF;
        }
    }
}

bool inRange(int y, int x) {
    if (0 <= y && y < N && 0 <= x && x < N) {
        return true;
    }
    return false;
}

struct node {
    int y;
    int x;
    int direction;
};

int bfs(vector<vector<int>>& board, int startY, int startX, int direction) {
    queue<node> q;
    
    cost[startY][startX] = 0;
    
    q.push({startY, startX, direction});
    
    while (!q.empty()) {
        node present = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nextDirect = (present.direction + i) % 4;
            int ny = present.y + dy[nextDirect];
            int nx = present.x + dx[nextDirect];
            int nextCost;
            
            if (nextDirect == present.direction) {
                nextCost = cost[present.y][present.x] + 100;
            }
            else {
                nextCost = cost[present.y][present.x] + 600;
            }
            
            if (inRange(ny, nx) && board[ny][nx] == 0 && cost[ny][nx] >= nextCost) {
                cost[ny][nx] = nextCost;
                q.push({ny, nx, nextDirect});
            }
        }
    }
    
    return cost[N-1][N-1];
}

int solution(vector<vector<int>> board) {
    int answer = INF;
    
    N = board.size();
    
    for (int i = 0; i < 4; i++) {
        init();
        answer = min(answer, bfs(board, 0, 0, i));
    }
    
    return answer;
}