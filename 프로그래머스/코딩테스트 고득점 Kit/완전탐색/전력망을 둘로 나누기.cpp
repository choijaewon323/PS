#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int ans = INT32_MAX;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> result;
int temp;

void dfs(int n, int start)
{
    visited[start] = true;
    
    for (int i = 0; i < adj[start].size(); i++)
    {
        int next = adj[start][i];
        
        if (!visited[next])
        {
            dfs(n, next);
        }
    }
    
    temp++;
}

void func(int n, vector<vector<int>>& wires)
{
    for (int i = 0; i < wires.size(); i++)
    {
        adj = vector<vector<int>>(n + 1);
        visited = vector<bool>(n + 1, false);
        result = vector<int>();
    
        for (int j = 0; j < wires.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            
            int a = wires[j][0];
            int b = wires[j][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                temp = 0;
                dfs(n, i);
                result.push_back(temp);
            }
        }
        
        ans = min(ans, abs(result[0] - result[1]));
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    func(n, wires);
    
    answer = ans;
    
    return answer;
}