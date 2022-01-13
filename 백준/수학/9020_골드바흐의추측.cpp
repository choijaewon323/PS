#include <iostream>
#include <vector>
using namespace std;
vector<bool> isPrime(10001, true);
void func(vector<int>& primeNumbers, int n, int interval) {
	if (interval == n) {
		return;
	}
	for (int i = 0; i < primeNumbers.size() - interval; i++) {
		if (primeNumbers[i] + primeNumbers[i + interval] == n) {
			cout << primeNumbers[i] << " " << primeNumbers[i + interval] << '\n';
			return;
		}
	}
	func(primeNumbers, n, interval + 1);
}
int main() {
	isPrime[0] = isPrime[1] = false;
	vector<int> primeNumbers;
	for (int i = 2; i <= 10000; i++) {
		if (isPrime[i]) {
			primeNumbers.push_back(i);
			for (int j = i * 2; j <= 10000; j += i) {
				isPrime[j] = false;
			}
		}
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		func(primeNumbers, n, 0);
	}
	return 0;
}