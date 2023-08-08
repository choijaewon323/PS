#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];

int find(int x) {
    if (parent[x] != x) {
        return parent[x] = find(parent[x]);
    }
    return x;
}

bool merge(int a, int b) {
    int aRoot = find(a);
    int bRoot = find(b);
    
    if (aRoot == bRoot) {
        return false;
    }
    
    if (aRoot < bRoot) {
        parent[bRoot] = aRoot;
    }
    else {
        parent[aRoot] = bRoot;
    }
    
    return true;
}

bool compare(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

void init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), compare);
    
    init(n);
    
    for (vector<int>& cost : costs) {
        int a = cost[0];
        int b = cost[1];
        
        if (merge(a, b)) {
            answer += cost[2];
        }
    }
    
    return answer;
}