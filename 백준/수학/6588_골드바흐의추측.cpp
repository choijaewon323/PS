#include <iostream>
#include <vector>
using namespace std;
bool isPrime[1000001];
void func(vector<int>& oddPrime, int number) {
	for (int i = 0; i < oddPrime.size() - 1; i++) {
		for (int j = i; j < oddPrime.size(); j++) {
			if (number == (oddPrime[i] + oddPrime[j])) {
				cout << number << " = " << oddPrime[i] << " + " << oddPrime[j] << '\n';
				return;
			}
			if (oddPrime[i] + oddPrime[j] > number) {
				break;
			}
		}
	}
	cout << "\"Goldbach\'s conjecture is wrong.\"" << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i <= 1000000; i++) {
		if (i % 2 == 0) {
			continue;
		}
		isPrime[i] = true;
	}
	isPrime[0] = isPrime[1] = false;
	isPrime[2] = true;
	vector<int> oddPrime;
	for (int i = 3; i <= 1000000; i++) {
		if (isPrime[i]) {
			oddPrime.push_back(i);
			for (int j = i * 2; j <= 1000000; j += i) {
				isPrime[j] = false;
			}
		}
	}
	int n;
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		func(oddPrime, n);
	}
	return 0;
}