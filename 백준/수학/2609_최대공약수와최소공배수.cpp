#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int p, int q) {
	if (p < q) {
		swap(p, q);
	}
	if (q == 0)
	{
		return p;
	}
	return gcd(p - q, q);
}
int main() {
	int p, q;
	cin >> p >> q;
	int gc = gcd(p, q);
	int lc = (p / gc) * (q / gc) * gc;
	cout << gc << '\n' << lc << '\n';
	return 0;
}