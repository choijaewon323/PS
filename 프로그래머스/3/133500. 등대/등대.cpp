#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

/*
    1 - 0
    2 - 0
    3 - 0
    4 - 0
    5 - 3
    6 - 1
    7 - 1
    8 - 1

    num unseen
    1 - 0
    2 - 1
    3 - 0
    4 - 0
    5 - 0
    6 - 0
    7 - 0
    8 - 0
    9 - 2
    10 - 1
*/
#define MAX 100000

vector<int> edges[MAX + 1];
vector<int> nodes;
bool visited[MAX + 1];
vector<int> depth;
bool light[MAX + 1];

bool compare(int a, int b) {
    return depth[a] > depth[b];
}

void bfs(int root) {
    depth[root] = 0;
    visited[root] = true;
    queue<pair<int, int>> q;
    q.push({root, 0});
    
    while (!q.empty()) {
        int present = q.front().first;
        int presentDepth = q.front().second;
        q.pop();
        
        for (int next : edges[present]) {
            if (!visited[next]) {
                visited[next] = true;
                depth[next] = presentDepth + 1;
                q.push({next, presentDepth + 1});
            }
        }
    }
}

int findParent(int node) {
    for (int next : edges[node]) {
        if (depth[next] < depth[node]) {
            return next;
        }
    }
    return -1;
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    
    for (vector<int> edge : lighthouse) {
        int a = edge[0];
        int b = edge[1];
        
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    depth = vector<int>(n + 1, -1);
    bfs(1);
    
    for (int i = 1; i <= n; i++) {
        nodes.push_back(i);
        visited[i] = false;
    }
    
    sort(nodes.begin(), nodes.end(), compare);
    
    for (int node : nodes) {
        if (light[node]) {
            continue;
        }
        
        int parent = findParent(node);
        
        if (parent == -1) {
            bool flag = false;
            
            for (int next : edges[node]) {
                if (light[next]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                answer++;
            }
        }
        
        if (parent != -1 && !light[parent]) {
            light[parent] = true;
            answer++;
        }
    }
    
    return answer;
}