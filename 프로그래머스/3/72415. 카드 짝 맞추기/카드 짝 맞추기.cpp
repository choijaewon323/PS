#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

/*
    카드 16장이 뒷면을 위로 하여 4 x 4 크기 격자 형태로 표시
    앞면에는 캐릭터 8가지가 2장씩 무작위 배치
    
    2장 선택 -> 같은 그림이면 해당 카드는 게임 화면에서 사라짐
    아니면 원래 상태로 뒷면 보이도록
    
    모든 카드를 화면에서 사라지게 하면 게임 종료
    
    - 카드는 커서를 사용해서 선택
        -> 굵고 빨간 테두리 상자
    - 커서는 Ctrl 키와 방향키에 의해 이동
        - 왼위아오 중 하나 누르면, 그 방향으로 1칸 이동
        - Ctrl + 방향키 -> 누른 키 방향에 있는 가장 가까운 카드로 한번에 이동
            - 만약 해당 방향에 카드가 하나도 없다면 가장 마지막 칸으로 이동
        - 만약 누른 키 방향으로 이동 가능한 카드 또는 빈공간이 없어
            이동 불가능하면 커서 안 움직임
    
    남은 카드를 모두 제거하는 데 필요한 키 조작 횟수의 최솟값을 구함
    방향키, Enter, Ctrl+방향 -> 1회
    
    배열이 4 x 4 이므로 충분히 완전 탐색으로 가능할듯
*/

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3
#define INF 1000000000

vector<pair<int, int>> opposite[7];
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

bool inRange(int y, int x) {
    if (0 <= y && y < 4 && 0 <= x && x < 4) {
        return true;
    }
    return false;
}

pair<int, int> controlMove(vector<vector<int>>& board, int y, int x, int direction) {
    int resultY = y;
    int resultX = x;
    
    switch (direction) {
        case LEFT:
            while (inRange(resultY, resultX - 1)) {
                resultX--;
                if (board[resultY][resultX] > 0) {
                    break;
                }
            }
            break;
        case UP:
            while (inRange(resultY - 1, resultX)) {
                resultY--;
                if (board[resultY][resultX] > 0) {
                    break;
                }
            }
            break;
        case RIGHT:
            while (inRange(resultY, resultX + 1)) {
                resultX++;
                if (board[resultY][resultX] > 0) {
                    break;
                }
            }
            break;
        case DOWN:
            while (inRange(resultY + 1, resultX)) {
                resultY++;
                if (board[resultY][resultX] > 0) {
                    break;
                }
            }
            break;
    }
    
    return {resultY, resultX};
}

int minMove(vector<vector<int>> board, int startY, int startX, int endY, int endX) {
    queue<pair<int, int>> q;
    vector<vector<int>> dist(4, vector<int>(4, -1));
    dist[startY][startX] = 0;
    q.push({startY, startX});
    
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if (y == endY && x == endX) {
            return dist[y][x];
        }
        
        // one move
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (inRange(ny, nx) && dist[ny][nx] == -1) {
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
        
        // control Move
        for (int i = 0; i < 4; i++) {
            pair<int, int> next = controlMove(board, y, x, i);
            
            if (dist[next.first][next.second] == -1) {
                dist[next.first][next.second] = dist[y][x] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

bool isEnd(vector<vector<int>> board) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (board[y][x] != 0) {
                return false;
            }
        }
    }
    return true;
}

pair<int, int> getOpposite(int y, int x, int myNum) {
    vector<pair<int, int>> oppo = opposite[myNum];
    for (pair<int, int>& op : oppo) {
        if (op.first == y && op.second == x) {
            continue;
        }
        return op;
    }
    return {-1, -1};
}

int solve(vector<vector<int>> board, int r, int c) {
    if (isEnd(board)) {
        return 0;
    }
    
    if (board[r][c] == 0) {
        int result = INF;
        
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                if (board[y][x] > 0) {
                    int cost = minMove(board, r, c, y, x);
                    result = min(result, cost + solve(board, y, x));
                }
            }
        }
        return result;
    }
    
    int myNum = board[r][c];
    pair<int, int> oppo = getOpposite(r, c, myNum);
    int cost = minMove(board, r, c, oppo.first, oppo.second);
    board[r][c] = 0;
    board[oppo.first][oppo.second] = 0;
    cost += 2;
    
    return solve(board, oppo.first, oppo.second) + cost;
}

int solution(vector<vector<int>> board, int r, int c) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (board[y][x] > 0) {
                opposite[board[y][x]].push_back({y, x});
            }
        }
    }
    int answer = solve(board, r, c);
    return answer;
}