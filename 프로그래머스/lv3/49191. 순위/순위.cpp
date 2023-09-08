#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 100

bool edge[MAX + 1][MAX + 1];

void transitiveClosure(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (edge[i][k] && edge[k][j]) {
                    edge[i][j] = true;
                }
            }
        }
    }    
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for (vector<int>& result : results) {
        int win = result[0];
        int lose = result[1];
        edge[win][lose] = true;
    }
    
    transitiveClosure(n);
    
    for (int i = 1; i <= n; i++) {
        // win calculation
        int win = 0;
        for (int j = 1; j <= n; j++) {
            if (edge[i][j]) {
                win++;
            }
        }
        
        // lose calculation
        int lose = 0;
        for (int j = 1; j <= n; j++) {
            if (edge[j][i]) {
                lose++;
            }
        }
        
        if (win + lose == n - 1) {
            answer++;
        }
    }
    
    return answer;
}