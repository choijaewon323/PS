#include <iostream>
using namespace std;
bool isPrime[246913];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i <= 246912; i++) {
		isPrime[i] = true;
	}
	isPrime[0] = isPrime[1] = false;
	for (int num = 2; num <= 246912; num++) {
		if (isPrime[num]) {
			for (int j = num * 2; j <= 246913; j += num) {
				isPrime[j] = false;
			}
		}
	}
	int number;
	while (true) {
		cin >> number;
		if (number == 0) {
			break;
		}
		int result = 0;
		for (int i = number + 1; i <= number * 2; i++) {
			if (isPrime[i]) {
				result++;
			}
		}
		cout << result << '\n';
	}
}