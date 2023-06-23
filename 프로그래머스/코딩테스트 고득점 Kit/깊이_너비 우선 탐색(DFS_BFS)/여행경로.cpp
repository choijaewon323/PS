#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef struct _edge
{
    string start;
    string end;
    bool used = false;
} edge;

vector<edge> edges;
vector<string> result;

bool compare(edge& a, edge& b)
{
    return a.end < b.end;
}

void dfs(string start)
{
    for (int i = 0; i < edges.size(); i++)
    {
        edge& temp = edges[i];
        
        if (temp.start == start && !temp.used)
        {
            temp.used = true;
            dfs(temp.end);
        }
    }
    
    result.push_back(start);
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    for (auto ticket : tickets)
    {
        edge temp = {ticket[0], ticket[1], false};
        edges.push_back(temp);
    }
    
    sort(edges.begin(), edges.end(), compare);
    
    dfs("ICN");
    
    reverse(result.begin(), result.end());
    
    answer = result;
    
    return answer;
}