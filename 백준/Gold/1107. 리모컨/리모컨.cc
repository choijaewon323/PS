#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

int N, M;
bool disable[10];

int absolute(int num) {
	if (num < 0) {
		return -num;
	}
	return num;
}

int onlyPlusAndMinus() {
	return absolute(N - 100);
}

int numberLength(int n) {
	if (n == 0) {
		return 1;
	}
	int result = 0;
	while (n != 0) {
		result++;
		n /= 10;
	}
	return result;
}

bool isImpossible(int n) {
	if (n == 0 && disable[0]) {
		return true;
	}

	if (n == 0 && !disable[0]) {
		return false;
	}

	while (n != 0) {
		if (disable[n % 10]) {
			return true;
		}
		n /= 10;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		disable[num] = true;
	}

	int answer = onlyPlusAndMinus();

	if (N == 100) {
		cout << 0 << '\n';
		return 0;
	}

	if (M == 10) {
		cout << answer << '\n';
		return 0;
	}

	for (int num = 0; num <= 999999; num++) {
		if (isImpossible(num)) {
			continue;
		}

		int temp = numberLength(num);
		temp += absolute(N - num);
		answer = min(answer, temp);
	}

	cout << answer << '\n';

	return 0;
}