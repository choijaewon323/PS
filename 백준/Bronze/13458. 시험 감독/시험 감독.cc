#include <iostream>
using namespace std;

#define MAX 1000000
typedef long long LL;

int N, B, C;
LL students[MAX];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> students[i];
	}
	cin >> B >> C;
}

LL solve() {
	LL result = 0;
	for (int i = 0; i < N; i++) {
		result++;
		students[i] -= B;
	}

	for (int i = 0; i < N; i++) {
		if (students[i] <= 0) {
			continue;
		}

		LL need = students[i] / C;
		int rest = students[i] % C;
		
		if (rest != 0) {
			need++;
		}

		result += need;
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