#include <string>
#include <vector>

using namespace std;

bool discovered[200];

void dfs(int start, int n, vector<vector<int>>& computers) {
    discovered[start] = true;
    
    for (int i = 0; i < n; i++) {
        if (computers[start][i] == 1 && start != i && !discovered[i]) {
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (!discovered[i]) {
            dfs(i, n, computers);
            answer++;
        }
    }
    
    return answer;
}