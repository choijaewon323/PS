#include <iostream>
using namespace std;
int main() {
	int n;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n) {
		long long count = 1;
		for (unsigned long long i = 1; ; i = i * 10 + 1) {
			if (i % n == 0)
			{
				break;
			}
			count++;
			i %= n;
		}
		cout << count << '\n';
	}
	return 0;
}