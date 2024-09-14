#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 50
#define EMPTY 0
#define WALL 1
#define VIRUS 2
#define INF 1000000000

int N, M;

vector<pair<int, int>> allVirus;
int allSize;
int lab[MAX][MAX];
int answer = INF;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

bool inRange(int y, int x) {
    return (0 <= y && y < N && 0 <= x && x < N);
}

int getSeconds(vector<vector<int>>& dist) {
    int seconds = -1;
    
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (lab[y][x] == VIRUS) {
                continue;
            }
            
            seconds = max(seconds, dist[y][x]);
        }
    }

    return seconds;
}

bool isAllVirus(vector<vector<int>>& dist) {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (lab[y][x] == WALL) {
                continue;
            }

            if (lab[y][x] == EMPTY && dist[y][x] == -1) {
                return false;
            }
        }
    }

    return true;
}

int bfs(vector<pair<int, int>>& startVirus) {
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<pair<int, int>> q;
    
    for (auto& start : startVirus) {
        dist[start.first][start.second] = 0;
        q.push(start);
    }

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (inRange(ny, nx) &&
            dist[ny][nx] == -1 &&
            lab[ny][nx] != WALL) {
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    int seconds = getSeconds(dist);
    
    if (isAllVirus(dist)) {
        return seconds;
    }

    return INF;
}

vector<pair<int, int>> getStart(vector<int>& index) {
    vector<pair<int, int>> result;

    for (int idx : index) {
        result.push_back(allVirus[idx]);
    }

    return result;
}

void solve(int prev, vector<int> index) {
    if (index.size() == M) {
        vector<pair<int, int>> tempStart = getStart(index);

        int tempAnswer = bfs(tempStart);

        answer = min(answer, tempAnswer);
        return;
    }

    for (int i = prev + 1; i < allSize; i++) {
        index.push_back(i);
        solve(i, index);
        index.pop_back();
    }
}

bool isAlreadyVirus() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (lab[y][x] == EMPTY) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int y = 0; y < N; y++){
        for (int x = 0; x < N; x++) {
            cin >> lab[y][x];

            if (lab[y][x] == VIRUS) {
                allVirus.push_back({y, x});
            }
        }
    }

    if (isAlreadyVirus()) {
        cout << 0 << '\n';
        return 0;
    }

    allSize = allVirus.size();

    solve(-1, vector<int>());

    if (answer == INF) {
        cout << -1 << '\n';
        return 0;
    }
    cout << answer << '\n';

    return 0;
}