#include <iostream>
using namespace std;
int dice[7];
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	dice[a]++;
	dice[b]++;
	dice[c]++;
	int result;
	bool flag = true;
	int max = 0;
	for (int i = 1; i <= 6; i++) {
		if (dice[i] == 3) {
			result = 10000 + i * 1000;
			flag = false;
			break;
		}
		if (dice[i] == 2) {
			result = 1000 + i * 100;
			flag = false;
			break;
		}
		if (dice[i] == 1) {
			max = i;
		}
	}
	if (flag) {
		result = max * 100;
	}
	cout << result << '\n';
	return 0;
}