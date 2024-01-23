#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll A, B, C;

void input() {
	cin >> A >> B >> C;
}

ll solve(const ll number, const ll power, const ll mod) {
	if (power == 0) {
		return 1;
	}

	if (power % 2 == 0) {
		return (solve(number, power / 2, mod) % mod *
			solve(number, power / 2, mod) % mod) % mod;
	}
	else {
		return (solve(number, power - 1, mod) % mod * number % mod) % mod;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	
	cout << solve(A, B, C) << '\n';

	return 0;
}