#include <iostream>
using namespace std;
unsigned long long f[1000001];
unsigned long long g[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 1; i <= 1000000; i++) {
		for (int j = 1; i * j <= 1000000; j++) {
			f[i * j] += i;
		}
	}
	g[1] = f[1];
	for (int i = 2; i <= 1000000; i++) {
		g[i] = g[i - 1] + f[i];
	}
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		cout << g[n] << '\n';
	}
	return 0;
}