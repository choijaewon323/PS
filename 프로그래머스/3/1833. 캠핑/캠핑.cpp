#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

bool isPossible(int i, int j, vector<vector<int>>& data) {
    int y1 = data[i][0];
    int x1 = data[i][1];
    int y2 = data[j][0];
    int x2 = data[j][1];
    
    for (int k = i + 1; k < j; k++) {
        int y3 = data[k][0];
        int x3 = data[k][1];
        
        if (y1 < y3 && 
            y3 < y2 && 
            min(x1, x2) < x3 && 
            x3 < max(x1, x2)) {
            return false;            
        }
    }
    return true;
}

int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    sort(data.begin(), data.end());
    
    for (int i = 0; i < n; i++) {
        int y1 = data[i][0];
        int x1 = data[i][1];
        
        for (int j = i + 1; j < n; j++) {
            int y2 = data[j][0];
            int x2 = data[j][1];
            
            if (y1 == y2 || x1 == x2) {
                continue;
            }
            
            if (isPossible(i, j, data)) {
                answer++;
            }
        }
    }
    
    return answer;
}