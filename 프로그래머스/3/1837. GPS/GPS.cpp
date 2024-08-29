#include <vector>
using namespace std;

/*
    승차 위치, 하차 위치는 오류 없음
    도로는 무방향 그래프
    거점 간의 이동은 해당 도로가 있는 경우 가능
    
    dp[i][j] : i 시간에 j 로 가기 위해 필요한 최소 수정 수
*/

#define NODE_MAX 200
#define TIME_MAX 100
#define INF 1000000000

vector<int> edges[NODE_MAX + 1];
int dp[TIME_MAX][NODE_MAX + 1];

void init(vector<vector<int>>& edge_list, int n, int k) {
    for (int i = 0; i < NODE_MAX; i++) {
        edges[i].clear();
    }
    
    for (vector<int>& edge : edge_list) {
        int a = edge[0];
        int b = edge[1];
        
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = INF;
        }
    }
}

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    init(edge_list, n, k);
    
    dp[0][gps_log[0]] = 0;
    
    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            int prevCount = dp[i - 1][j];
            int present = gps_log[i];
            
            for (int edge : edges[j]) {
                if (present == edge) {
                    dp[i][edge] = min(dp[i][edge], prevCount);
                } else {
                    dp[i][edge] = min(dp[i][edge], prevCount + 1);
                }
            }
        }
    }
    
    int answer = dp[k - 1][gps_log[k - 1]];
    
    if (answer == INF) {
        return -1;
    }
    
    return answer;
}