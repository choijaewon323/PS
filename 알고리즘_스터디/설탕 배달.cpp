#include <iostream>
using namespace std;

int main() {
	int n, count = 0;

	cin >> n;

	if ( n == 4 )
	{
		cout << -1 << endl;
		return 0;
	}
	if ( n == 7 ) {
		cout << -1 << endl;
		return 0;
	}

	while ( 1 ) {
		if ( n == 3 || n == 5 || n == 1) {
			count++;
			break;
		}

		if ( n == 2 || n == 4 ) {
			count++;
			count++;
			break;
		}

		count++;
		n -= 5;
	}

	cout << count << endl;

	return 0;
}