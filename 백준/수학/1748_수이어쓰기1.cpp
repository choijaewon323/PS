#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int sum = 9;
	int result = 0;
	int count = 1;
	for (int i = 1; i <= 9; i++) {
		if (n >= count && n > count * 10 - 1) {
			result += (sum * i);
			sum *= 10;
			count *= 10;
		}
		else if (n >= count && n <= count * 10 - 1) {
			result += (n - count + 1) * i;
			break;
		}
	}
	cout << result << '\n';
	return 0;
}