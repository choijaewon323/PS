#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MOD 1000000007

typedef long long LL;

LL calculate(LL a, LL x) {
	if (x == 0) {
		return 1;
	}

	if (x % 2 == 1) {
		return calculate(a, x - 1) % MOD * a % MOD;
	} else {
		LL result = calculate(a, x / 2) % MOD;
		return result % MOD * result % MOD;
	}
}

int M;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	LL answer = 0;
	cin >> M;
	for (int i = 0; i < M; i++) {
		LL N, S;
		cin >> N >> S;
		LL result = S * calculate(N, MOD - 2) % MOD;
		answer += result;
		answer %= MOD;
	}
	cout << answer << '\n';
	return 0;
}