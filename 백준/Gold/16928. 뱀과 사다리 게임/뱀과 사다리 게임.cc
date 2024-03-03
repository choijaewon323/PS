#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

#define NUMBER_MAX 100
#define INF 1000000000

int N, M;
int ladder[NUMBER_MAX + 1];
int snake[NUMBER_MAX + 1];
vector<int> dist(NUMBER_MAX + 1, INF);

bool inRange(int next) {
	if (next <= 100) {
		return true;
	}
	return false;
}

void solve(int number, int cnt) {
	if (number == 100) {
		dist[100] = min(dist[100], cnt);
		return;
	}

	for (int i = 1; i <= 6; i++) {
		int next = number + i;

		if (ladder[next] != 0) {
			next = ladder[next];
		} else if (snake[next] != 0) {
			next = snake[next];
		}

		if (inRange(next) && dist[next] > cnt + 1) {
			dist[next] = cnt + 1;
			solve(next, cnt + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		ladder[x] = y;
	}
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		snake[u] = v;
	}

	dist[1] = 0;
	solve(1, 0);

	cout << dist[100] << '\n';

	return 0;
}