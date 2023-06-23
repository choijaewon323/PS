#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

#define MAX 20000

vector<int> edges[MAX + 1];
int visited[MAX + 1];

void bfs(int start)
{
    queue<int> q;
    
    visited[start] = 1;
    q.push(start);
    
    while (!q.empty())
    {
        int present = q.front();
        q.pop();
        
        for (int i = 0; i < edges[present].size(); i++)
        {
            int next = edges[present][i];
            
            if (visited[next] == 0)
            {
                visited[next] = visited[present] + 1;
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for (auto i : edge)
    {
        int a = i[0];
        int b = i[1];
        
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    bfs(1);
    
    int maxNode = -1;
    for (int i = 1; i <= n; i++)
    {
        maxNode = max(maxNode, visited[i]);
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == maxNode)
        {
            answer++;
        }
    }
    
    return answer;
}