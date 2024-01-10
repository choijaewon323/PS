#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1000

void calculate(vector<vector<int>>& board) {
    int rowSize = board.size();
    int columnSize = board[0].size();
    
    for (int y = 1; y < rowSize; y++) {
        for (int x = 1; x < columnSize; x++) {
            if (board[y][x] == 0) {
                continue;
            }
            
            board[y][x] = min(board[y - 1][x], min(board[y][x - 1], board[y - 1][x - 1])) + 1;
        }
    }
}

int findAnswer(vector<vector<int>>& board) {
    int result = 0;
    int rowSize = board.size();
    int columnSize = board[0].size();
    
    for (int y = 0; y < rowSize; y++) {
        for (int x = 0; x < columnSize; x++) {
            result = max(result, board[y][x]);
        }
    }
    
    return result;
}

int solution(vector<vector<int>> board)
{
    int rowSize = board.size();
    int columnSize = board[0].size();
    
    if (rowSize == 1 && columnSize == 1) {
        return board[0][0];
    }
    
    calculate(board);
    int answer = findAnswer(board);
    
    return answer * answer;
}