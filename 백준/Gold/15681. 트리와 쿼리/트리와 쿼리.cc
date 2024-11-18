#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 100000

vector<int> edges[MAX + 1];
int ans[MAX + 1];
int N, R, Q;
bool visited[MAX + 1];

int dfs(int start) {
    visited[start] = true;
    int answer = 1;

    for (int next : edges[start]) {
        if (!visited[next]) {
            answer += dfs(next);
        }
    }

    return ans[start] = answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R >> Q;
    for (int i = 0; i < N - 1; i++) {
        int u, v;

        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    dfs(R);

    for (int i = 0; i < Q; i++) {
        int temp;
        cin >> temp;
        cout << ans[temp] << '\n';
    }

    return 0;
}