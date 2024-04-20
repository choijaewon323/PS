#include <iostream>
#include <vector>
using namespace std;

#define MAX 4000000

int N;
bool isPrime[MAX + 1];
vector<int> primes;

void init() {
	for (int i = 0; i <= MAX; i++) {
		isPrime[i] = true;
	}
}

void eratos() {
	for (int i = 2; i * i <= MAX; i++) {
		if (!isPrime[i]) {
			continue;
		}

		for (int j = i * i; j <= MAX; j += i) {
			isPrime[j] = false;
		}
	}

	for (int i = 2; i <= MAX; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
		}
	}
}

void input() {
	cin >> N;
}

int findAnswer() {
	int size = primes.size();
	int left = 0;
	int right = 0;
	int acc = 2;
	int result = 0;
	
	while (right < size && left <= right) {
		if (left == right) {
			if (acc == N) {
				result++;
			}

			right++;
			if (right < size) {
				acc += primes[right];
			}
		} else {
			if (acc <= N) {
				if (acc == N) {
					result++;
				}

				right++;
				if (right < size) {
					acc += primes[right];
				}
			} else {
				acc -= primes[left];
				left++;
			}
		}
	}

	return result;
}

int solve() {
	return findAnswer();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	eratos();
	input();
	cout << solve() << '\n';

	return 0;
}