#include <string>
#include <vector>

using namespace std;

int acc[1003][1003];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    for (vector<int>& sk : skill) {
        int type = sk[0];
        int r1 = sk[1];
        int c1 = sk[2];
        int r2 = sk[3];
        int c2 = sk[4];
        int degree = sk[5];
        
        if (type == 1) {
            degree = -degree;
        }
        
        acc[r1][c1] += degree;
        acc[r1][c2 + 1] += -degree;
        acc[r2 + 1][c1] += -degree;
        acc[r2 + 1][c2 + 1] += degree;
    }
    
    for (int y = 0; y < 1003; y++) {
        for (int x = 0; x < 1002; x++) {
            acc[y][x + 1] += acc[y][x];
        }
    }
    
    for (int x = 0; x < 1003; x++) {
        for (int y = 0; y < 1002; y++) {
            acc[y + 1][x] += acc[y][x];
        }
    }
    
    for (int y = 0; y < board.size(); y++) {
        for (int x = 0; x < board[0].size(); x++) {
            if (board[y][x] + acc[y][x] >= 1) {
                answer++;
            }
        }
    }
    
    return answer;
}