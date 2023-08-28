#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> visited;
vector<int> edges[100001];

int bfs(int start, int dest, int n) {
    visited = vector<int>(n + 1, 0);
    
    queue<int> q;
    
    visited[start] = 1;
    q.push(start);
    
    while (!q.empty()) {
        int present = q.front();
        q.pop();
        
        if (present == dest) {
            return visited[present] - 1;
        }
        
        for (int i = 0; i < edges[present].size(); i++) {
            int next = edges[present][i];
            
            if (!visited[next]) {
                q.push(next);
                visited[next] = visited[present] + 1;
            }
        }
    }
    
    return -1;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    for (vector<int>& road : roads) {
        int a = road[0];
        int b = road[1];
        
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    for (int source : sources) {
        int result = bfs(source, destination, n);
        
        answer.push_back(result);
    }
    
    return answer;
}