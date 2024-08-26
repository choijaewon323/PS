#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>

using namespace std;

#define MAX 100
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

struct Node {
    int y;
    int x;
    int direction;
    int cnt;
};

int M, N;

bool inRange(int y, int x) {
    return (0 <= y && y < M && 0 <= x && x < N);
}

bool isAllClear(vector<vector<pair<int, int>>>& alphabet) {
    for (vector<pair<int, int>>& a : alphabet) {
        if (!a.empty()) {
            return false;
        }
    }
    return true;
}

int moveLeft(int direction) {
    direction--;
    if (direction < 0) {
        direction += 4;
    }
    return direction;
}

int moveRight(int direction) {
    direction++;
    direction %= 4;
    return direction;
}

pair<int, int> nextPos(int y, int x, int direction) {
    switch (direction) {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case RIGHT:
            x++;
            break;
        case LEFT:
            x--;
            break;
    }
    return {y, x};
}

bool isRemovable(pair<int, int>& start, pair<int, int>& end, vector<string>& board) {
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    visited[start.first][start.second] = true;
    char initialAlpha = board[start.first][start.second];
    
    queue<Node> q;
    
    for (int i = 0; i < 4; i++) {
        q.push({start.first, start.second, i, 0});
    }
    
    while (!q.empty()) {
        Node present = q.front();
        q.pop();
        
        if (present.y == end.first && present.x == end.second) {
            return true;
        }
        
        // 1. move straight
        pair<int, int> next = nextPos(present.y, present.x, present.direction);
        if (inRange(next.first, next.second) && 
            //!visited[next.first][next.second] && 
            (board[next.first][next.second] == '.' || board[next.first][next.second] == initialAlpha)) {
            
            //visited[next.first][next.second] = true;
            q.push({next.first, next.second, present.direction, present.cnt});
        }
        
        // 2. move left 90
        if (present.cnt == 0) {
            int nextDirect = moveLeft(present.direction);
            pair<int, int> next = nextPos(present.y, present.x, nextDirect);
            
            if (inRange(next.first, next.second) && 
                //!visited[next.first][next.second] && 
                (board[next.first][next.second] == '.' || board[next.first][next.second] == initialAlpha)) {
                
                //visited[next.first][next.second] = true;
                q.push({next.first, next.second, nextDirect, present.cnt + 1});
            }
        }
        
        // 3. move right 90
        if (present.cnt == 0) {
            int nextDirect = moveRight(present.direction);
            pair<int, int> next = nextPos(present.y, present.x, nextDirect);
            
            if (inRange(next.first, next.second) && 
                //!visited[next.first][next.second] && 
                (board[next.first][next.second] == '.' || board[next.first][next.second] == initialAlpha)) {
                
                //visited[next.first][next.second] = true;
                q.push({next.first, next.second, nextDirect, present.cnt + 1});
            }
        }
    }
    return false;
}

vector<vector<pair<int, int>>> getAlphabet(vector<string>& board) {
    vector<vector<pair<int, int>>> alphabet(26);
    
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            char c = board[y][x];
            
            if (c == '.' || c == '*')
                continue;
            
            int index = c - 'A';
            
            alphabet[index].push_back({y, x});
        }
    }
    
    return alphabet;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";
    
    M = m;
    N = n;
    
    vector<vector<pair<int, int>>> alphabet = getAlphabet(board);
    
    while (true) {
        if (isAllClear(alphabet)) {
            break;
        }
        
        bool isExecuted = false;
        
        for (int i = 0; i < 26; i++) {
            vector<pair<int, int>>& index = alphabet[i];
            
            if (index.empty()) {
                continue;
            }
            
            //cout << (char)('A' + i) << '\n';
            
            pair<int, int> start = index[0];
            pair<int, int> end = index[1];
            
            if (isRemovable(start, end, board)) {
                //cout << (char)('A' + i) << " is removable" << '\n';
                isExecuted = true;
                index.clear();
                board[start.first][start.second] = '.';
                board[end.first][end.second] = '.';
                answer += ('A' + i);
                break;
            }
        }
        
        if (!isExecuted) {
            return "IMPOSSIBLE";
        }
    }
    
    return answer;
}