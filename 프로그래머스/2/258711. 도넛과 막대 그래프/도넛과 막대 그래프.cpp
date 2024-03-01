#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
    도넛, 막대, 8자 그래프 존재
    1개 이상의 정점, 단방향 간선으로 이루어짐 -> 유향 그래프

    도넛 모양 그래프
        크기가 n 이면 n개의 정점, n개의 간선 있음
        아무 한 정점에서 출발해 이용한 적 없는 간선 따라가면 나머지 n - 1 개 정점 한번씩 방문 뒤
        원래 출발했던 정점으로 돌아옴
    
    막대 모양 그래프
        크기가 n이면 n개의 정점, n - 1개의 간선 있음
        임의의 한 정점에서 출발해 간선을 계속 따라가면 나머지 n - 1 개의 정점을 한번씩
        방문하게 되는 정점 단 하나 존재
    
    8자 모양 그래프
        크기가 n이면 2n + 1개의 정점, 2n + 2 개의 간선 있음
        크기가 동일한 2개의 도넛 모양 그래프에서 정점을 하나씩 고랄 결합시킨 형태의 그래프

    여러개의 그래프들, 거기에 무관한 정점을 하나 생성한 뒤,
    각 그래프의 임의의 정점 하나로 향하는 간선 연결한 뒤 각 정점에 서로 다른 번호 매김

    결과 : 생성한 정점의 번호, 정점을 생성하기 전 도넛, 막대, 8자 그래프 수 구해야함

    입력 조건
    edges의 길이 <= 1,000,000
    [a, b] 형태 : a -> b 존재

    알고리즘 구상

    일단 incoming edge 가 하나도 없으면서, outgoing edge 가 가장 많은 것이 생성 정점

*/

#define MAX 1000000
#define START 0
#define DONUT 1
#define STICK 2
#define EIGHT 3

vector<int> edge[MAX + 1];
int incoming[MAX + 1];
int outgoing[MAX + 1];

int findStart() {
    vector<int> zeroIncomings;

    for (int i = 1; i <= MAX; i++) {
        if (incoming[i] == 0) {
            zeroIncomings.push_back(i);
        }
    }

    int result = -1;
    for (int temp : zeroIncomings) {
        if (result == -1) {
            result = temp;
            continue;
        }

        if (outgoing[temp] > outgoing[result]) {
            result = temp;
        }
    } 

    return result;
}

bool isStick(int start) {
    vector<bool> visited(MAX + 1, false);

    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int present = q.front();
        q.pop();

        int presentSize = edge[present].size();
        for (int i = 0; i < presentSize; i++) {
            int next = edge[present][i];

            if (visited[next]) {
                return false;
            }

            visited[next] = true;
            q.push(next);
        }
    }

    return true;
}

int isDonutOrEight(int start) {
    vector<bool> visited(MAX + 1, false);

    queue<int> q;

    visited[start] = true;
    q.push(start);

    if (outgoing[start] > 1) {
        return EIGHT;
    }

    while (!q.empty()) {
        int present = q.front();
        q.pop();

        int presentSize = edge[present].size();

        if (presentSize > 1) {
            return EIGHT;
        }

        for (int i = 0; i < presentSize; i++) {
            int next = edge[present][i];
            
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }

    return DONUT;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer = {0, 0, 0, 0};

    for (vector<int>& ed : edges) {
        int a = ed[0];
        int b = ed[1];

        edge[a].push_back(b);
        incoming[b]++;
        outgoing[a]++;
    }

    int start = findStart();

    answer[START] = start;

    int startSize = edge[start].size();
    for (int i = 0; i < startSize; i++) {
        int adjacent = edge[start][i];

        if (isStick(adjacent)) {
            answer[STICK]++;
            continue;
        }

        int judge = isDonutOrEight(adjacent);

        answer[judge]++;
    }

    return answer;
}