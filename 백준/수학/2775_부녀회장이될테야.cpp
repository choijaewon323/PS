#include <iostream>
using namespace std;
int apartment[15][15];
int main() {
	for (int i = 1; i <= 14; i++) {
		apartment[0][i] = i;
	}
	for (int i = 1; i <= 14; i++) {
		int temp = 0;
		for (int j = 1; j <= 14; j++) {
			temp += apartment[i - 1][j];
			apartment[i][j] = temp;
		}
 	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int k;
		cin >> k;
		int n;
		cin >> n;
		cout << apartment[k][n] << '\n';
	}
	return 0;
}