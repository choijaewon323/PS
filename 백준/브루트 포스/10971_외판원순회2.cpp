#include <iostream>
#include <algorithm>
using namespace std;
int n;
int w[11][11];
bool isChecked[11];
int func(int firstCity, int present, int restCity) {
	if (firstCity == -1) {
		int result = 10000001;
		for (int first = 1; first <= n; first++) {
			result = min(result, func(first, first, n - 1));
		}
		return result;
	}
	if (restCity == 0) {
		if (w[present][firstCity] == 0) {
			return 10000001;
		}
		else {
			return w[present][firstCity];
		}
	}
	isChecked[present] = true;
	int result = 10000001;
	for (int next = 1; next <= n; next++) {
		if (!isChecked[next] && w[present][next] != 0) {
			result = min(result, w[present][next] + func(firstCity, next, restCity - 1));
		}
	}
	isChecked[present] = false;
	return result;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> w[i][j];
		}
	}
	cout << func(-1, -1, -1) << '\n';
	return 0;
}