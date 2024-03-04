#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000000000000ll
typedef long long LL;

LL A, B;

LL solve(LL num) {
	if (num > B) {
		return INF;
	}
	if (num == B) {
		return 0;
	}
	LL result = INF;
	
	// x 2
	result = min(result, solve(num * 2) + 1);

	// add a
	result = min(result, solve(num * 10 + 1) + 1);

	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B;
	
	LL result = solve(A);

	if (result >= INF) {
		cout << -1 << '\n';
	} else {
		cout << result + 1 << '\n';
	}

	return 0;
}