#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

/*
    트리 형식임에 주목할 필요가 있다.
    
    하나는 +1, 하나는 -1 -> 준다라는 개념으로 봐야함
    
    리프부터 위로 올린다면?
    
    트리의 루트는? -> 간선이 2개인 것
    
    각 루트를 돌면서 최소로 드는 것을 확인
    
*/

#define NODE_MAX 300000
#define INF 10000000000000000ll
typedef long long LL;

vector<int> edges[NODE_MAX];
vector<int> roots;

bool isAllZero(vector<int> a)
{
    for (int number : a)
    {
        if (number != 0)
        {
            return false;
        }
    }
    return true;
}

bool isPossible(vector<int> a)
{
    LL result = 0;
    for (int number : a)
    {
        result += number;
    }
    if (result != 0)
    {
        return false;
    }
    return true;
}

LL cnt;
vector<bool> visited;

LL dfs(int num, vector<int>& a)
{
    visited[num] = true;
    
    LL result = a[num];
    for (int next : edges[num])
    {
        if (!visited[next])
        {
            result += dfs(next, a);
        }
    }
    
    cnt += abs(result);
    return result;
}

LL solution(vector<int> a, vector<vector<int>> eds) {
    if (isAllZero(a))
    {
        return 0;
    }
    
    int size = a.size();
    for (vector<int>& ed : eds)
    {
        int u = ed[0];
        int v = ed[1];
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    visited = vector<bool>(size, false);
    cnt = 0;
    LL result = dfs(0, a);
    
    if (result != 0)
    {
        return -1;
    }
    
    return cnt;
}