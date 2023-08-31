#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {0, 1, 0, 1};
int dy[] = {0, 0, 1, 1};

bool isSame(int y, int x, vector<string>& board) {
    if (board[y][x] == ' ') {
        return false;
    }
    
    char first = board[y][x];
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (first != board[ny][nx]) {
            return false;
        }
    }
    
    return true;
}

void makeTrue(int y, int x, vector<vector<bool>>& possible) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        possible[ny][nx] = true;
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while (true) {
        vector<vector<bool>> possible(m, vector<bool>(n, false));
        
        bool same = false;
        // 1. 순회
        for (int y = 0; y < m - 1; y++) {
            for (int x = 0; x < n - 1; x++) {
                // check and make true
                if (isSame(y, x, board)) {
                    same = true;
                    makeTrue(y, x, possible);
                }
            }
        }
        
        if (!same) {
            break;
        }
        
        // 2. count true and make blank
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (possible[y][x]) {
                    answer++;
                    board[y][x] = ' ';
                }
            }
        }
        
        // 3. move
        for (int x = 0; x < n; x++) {
            priority_queue<int> pq;
            
            for (int y = m - 1; y >= 0; y--) {
                if (board[y][x] == ' ') {
                    pq.push(y);
                }
                else {
                    if (!pq.empty()) {
                        int tempY = pq.top();
                        pq.pop();
                        char temp = board[y][x];
                        board[tempY][x] = temp;
                        board[y][x] = ' ';
                        pq.push(y);
                    }
                }
            }
        }
    }
    
    return answer;
}