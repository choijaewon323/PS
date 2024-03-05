#include <iostream>
#include <vector>
using namespace std;

#define INF INT64_MAX / 2
#define MAX 500

vector<pair<int, int>> edges[MAX + 1];

vector<long long> bellman_ford(int N) {
	vector<long long> dist(N + 1, INF);

	// 정점 개수만큼 반복
	for (int vertex = 1; vertex <= N - 1; vertex++) {
		// 모든 간선에 대해서 수행
		for (int present = 1; present <= N; present++) {
			for (int i = 0; i < edges[present].size(); i++) {
				int next = edges[present][i].first;
				int cost = edges[present][i].second;

				if (dist[next] > dist[present] + cost) {
					dist[next] = dist[present] + cost;
				}
			}
		}
	}

	// 음수 사이클 판정
	for (int present = 1; present <= N; present++) {
		for (int i = 0; i < edges[present].size(); i++) {
			int next = edges[present][i].first;
			int cost = edges[present][i].second;

			if (dist[next] > dist[present] + cost) {
				return vector<long long>();
			}
		}
	}

	return dist;
}

void init(int N) {
	for (int i = 1; i <= N; i++) {
		edges[i].clear();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;
	for (int test = 0; test < TC; test++) {
		int N, M, W;
		cin >> N >> M >> W;

		init(N);

		for (int i = 0; i < M; i++) {
			int S, E, T;
			cin >> S >> E >> T;

			edges[S].push_back({ E, T });
			edges[E].push_back({ S, T });
		}

		for (int i = 0; i < W; i++) {
			int S, E, T;
			cin >> S >> E >> T;

			edges[S].push_back({ E, -T });
		}

		vector<long long> result = bellman_ford(N);

		if (result.empty()) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}