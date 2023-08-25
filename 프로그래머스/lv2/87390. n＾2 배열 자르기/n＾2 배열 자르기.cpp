#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    long long leftRow = left / n + 1;
    long long leftCol = left % n + 1;
    
    long long rightRow = right / n + 1;
    long long rightCol = right % n + 1;
    
    // base case
    if (leftRow == rightRow && leftCol == rightCol) {
        answer.push_back(max(leftRow, leftCol));
        
        return answer;
    }
    
    long long row = leftRow;
    long long col = leftCol;
    
    while (!(row == rightRow && col == rightCol)) {
        answer.push_back(max(row, col));
        
        col++;
        if (col > n) {
            col = 1;
            row++;
        }
    }
    answer.push_back(max(rightRow, rightCol));
    
    return answer;
}