#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define MAX 1000

typedef long long LL;

int T, N, M;
int accA[MAX + 1];
int accB[MAX + 1];
map<int, LL> cnt;

void input() {
	cin >> T;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		accA[i] = temp + accA[i - 1];
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		int temp;
		cin >> temp;
		accB[i] = temp + accB[i - 1];
	}
}

bool inRangeA(int x) {
	return (0 <= x && x <= N);
}

bool inRangeB(int x) {
	return (0 <= x && x <= M);
}

LL solve() {
	for (int length = 1; length <= M; length++) {
		for (int end = 1; end <= M; end++) {
			int start = end - length;
			
			if (inRangeB(start)) {
				int present = accB[end] - accB[start];
				cnt[present]++;
			}
		}
	}
	LL result = 0;
	for (int length = 1; length <= N; length++) {
		for (int end = 1; end <= N; end++) {
			int start = end - length;

			if (inRangeA(start)) {
				int present = accA[end] - accA[start];
				int rest = T - present;
				result += cnt[rest];
			}
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve() << '\n';

	return 0;
}