#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<string, vector<string>> edges;
map<string, int> visited;

int bfs(string begin, string target)
{
    queue<string> q;
    visited[begin] = 1;
    
    q.push(begin);
    
    while (!q.empty())
    {
        string present = q.front();
        q.pop();
        
        if (present == target)
        {
            return visited[present] - 1;
        }
        
        for (int i = 0; i < edges[present].size(); i++)
        {
            string next = edges[present][i];
            
            if (visited[next] == 0)
            {
                visited[next] = visited[present] + 1;
                q.push(next);
            }
        }
    }
    
    return -1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool contained = false;
    
    for (auto w : words)
    {
        if (w == target)
        {
            contained = true;
            break;
        }
    }
    
    if (!contained)
    {
        return 0;
    }
    
    for (int i = 0; i < words.size(); i++)
    {
        int cnt = 0;
        for (int k = 0; k < begin.size(); k++)
        {
            if (begin[k] != words[i][k])
            {
                cnt++;
            }
        }
        
        if (cnt == 1)
        {
            edges[begin].push_back(words[i]);
            edges[words[i]].push_back(begin);
        }
    }
    
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            int cnt = 0;
            
            if (i == j)
            {
                continue;
            }
            
            for (int k = 0; k < words[i].size(); k++)
            {
                if (words[i][k] != words[j][k])
                {
                    cnt++;
                }
            }
            
            if (cnt == 1)
            {
                edges[words[i]].push_back(words[j]);
                edges[words[j]].push_back(words[i]);
            }
        }
    }
    
    answer = bfs(begin, target);
    
    if (answer == -1)
    {
        answer = 0;
    }
    
    return answer;
}