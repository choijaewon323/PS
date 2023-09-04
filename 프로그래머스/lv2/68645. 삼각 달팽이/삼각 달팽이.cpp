#include <string>
#include <vector>
#include <iostream>

using namespace std;

int number;

void fill(vector<vector<int>>& triangle, int n, int dist, int startY, int startX) {
    int endY = n - dist - 1;
    int endX = triangle[endY].size() - 1 - dist;
    
    // left
    for (int y = startY; y <= endY; y++) {
        triangle[y][dist] = number;
        number++;
    }
    
    // down
    for (int x = dist + 1; x <= endX; x++) {
        triangle[endY][x] = number;
        number++;
    }
    
    // right
    for (int y = endY - 1; y >= startY + 1; y--) {
        int last = triangle[y].size() - dist - 1;
        triangle[y][last] = number;
        number++;
    }
}

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> triangle(n);
    
    for (int i = 0; i < n; i++) {
        triangle[i] = vector<int>(i + 1, 0);
    }
    
    int cnt = (n - 1) / 3;
    
    int startY = 0, startX = 0;
    
    number = 1;
    
    for (int c = 0; c <= cnt; c++) {
        fill(triangle, n, c, startY, startX);
        startY += 2;
        startX += 1;
    }
    
    for (vector<int>& t : triangle) {
        for (int num : t) {
            answer.push_back(num);
        }
    }
    
    return answer;
}