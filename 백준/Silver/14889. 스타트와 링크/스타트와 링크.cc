#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 20
#define INF 1000000000

int N;
int S[MAX][MAX];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}
}

vector<int> makeLink(vector<int> &start) {
	vector<bool> visited(N, false);

	for (int s : start) {
		visited[s] = true;
	}

	vector<int> link;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			link.push_back(i);
		}
	}

	return link;
}

int calculate(vector<int> &some) {
	int result = 0;
	for (int i : some) {
		for (int j : some) {
			result += S[i][j];
		}
	}
	return result;
}

int absolute(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

int pickHalf(vector<int> &start, int prev) {
	if (start.size() == N / 2) {
		// some action

		vector<int> link = makeLink(start);
		int startRes = calculate(start);
		int linkRes = calculate(link);

		int result = absolute(startRes - linkRes);

		return result;
	}

	int result = INF;
	for (int i = prev + 1; i < N; i++) {
		start.push_back(i);
		result = min(result, pickHalf(start, i));
		start.pop_back();
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	vector<int> start;
	cout << pickHalf(start, -1) << '\n';
	
	return 0;
}