#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define HOUSE_MAX 50
#define INF 1000000000

int dist[HOUSE_MAX + 1][HOUSE_MAX + 1];

void floydWarshall(int N) {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][j] >= dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void init(int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                dist[i][j] = 0;
                
                continue;
            }
            dist[i][j] = INF;
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    init(N);
    
    for (vector<int> info : road) {
        int src = info[0];
        int dst = info[1];
        int cost = info[2];
        
        int resultCost = min(dist[src][dst], cost);
        
        dist[src][dst] = resultCost;
        dist[dst][src] = resultCost;
    }
    
    floydWarshall(N);
    
    for (int i = 1; i <= N; i++) {
        if (dist[1][i] <= K) {
            answer++;
        }
    }

    return answer;
}