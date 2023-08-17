#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 300000000

int dist[201][201];

void init() {
    for (int y = 0; y < 201; y++) {
        for (int x = 0; x < 201; x++) {
            if (y == x) {
                dist[y][x] = 0;
                continue;
            }
            dist[y][x] = INF;
        }
    }
}

void floyd_warshall(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

// s : 출발 지점, a와 b : 도착 지점
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    // 초기화
    init();
    dist[s][s] = 0;
    for (vector<int> fare : fares) {
        int c = fare[0];
        int d = fare[1];
        int cost = fare[2];
        
        dist[c][d] = cost;
        dist[d][c] = cost;
    }
    
    floyd_warshall(n);
    
    // 처음 answer : 따로 갔을 때의 답 - 처음 갈라지기 시작한 위치가 s
    int answer = dist[s][a] + dist[s][b];
    for (int i = 1; i <= n; i++) {
        if (i == s) {
            continue;   // 이미 계산했으므로
        }
        
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    
    return answer;
}