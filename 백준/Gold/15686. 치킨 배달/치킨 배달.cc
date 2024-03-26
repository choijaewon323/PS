#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

/*
	크기가 N * N인 도시 존재
	1 * 1 크기 칸으로 나누어짐

	각 칸은 빈칸, 치킨집, 집 중 하나이다.

	r, c는 1부터 시작한다.

	치킨 거리 -> 집과 가장 가까운 치킨집 사이의 거리

	도시의 치킨 거리는 모든 집의 치킨 거리의 합이다.

	일부 치킨집을 없애려고 함

	도시에 있는 치킨집 중 최대 M개를 고르고, 나머지는 모두 폐업
	어떻게 하면 도시의 치킨 거리가 가장 작게 될지 구하기

	bfs 사용했을 시 최악 시간 복잡도 : 2N * 13CM * N*N
	그냥 저장했다가 쓰는게 더 빨라보이는데?


*/

#define MAX 50
#define INF 1000000000

int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int absolute(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

int pick(vector<pair<int, int>> &temp, int index) {
	if (temp.size() == M) {
		// some action
		int result = 0;

		for (pair<int, int> &presentHouse : house) {
			int dist = INF;

			for (pair<int, int> &chick : temp) {
				int presentDist = absolute(chick.first - presentHouse.first)
					+ absolute(chick.second - presentHouse.second);
				
				dist = min(dist, presentDist);
			}

			result += dist;
		}

		return result;
	}

	int result = INF;
	for (int i = index + 1; i < chicken.size(); i++) {
		temp.push_back(chicken[i]);
		result = min(result, pick(temp, i));
		temp.pop_back();
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			int num;
			cin >> num;

			if (num == 1) {
				house.push_back({ y, x });
			} else if (num == 2) {
				chicken.push_back({ y, x });
			}
		}
	}

	vector<pair<int, int>> temp;
	int answer = pick(temp, -1);
	cout << answer << '\n';

	return 0;
}