#include <string>
#include <vector>

using namespace std;

int result[2];

void solve(int startY, int startX, int size, vector<vector<int>>& arr) {
    // 1. count
    int first = arr[startY][startX];
    
    bool flag = true;
    for (int y = startY; y < startY + size; y++) {
        for (int x = startX; x < startX + size; x++) {
            if (first != arr[y][x]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }
    
    // 2-1. all same
    if (flag) {
        result[first]++;
        return;
    }
    
    // 2-2. not all same
    for (int y = startY; y < startY + size; y += size / 2) {
        for (int x = startX; x < startX + size; x += size / 2) {
            solve(y, x, size / 2, arr);
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    solve(0, 0, arr.size(), arr);
    
    answer.push_back(result[0]);
    answer.push_back(result[1]);
    
    return answer;
}