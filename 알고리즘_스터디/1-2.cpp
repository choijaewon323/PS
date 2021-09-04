#include <iostream>
#include <vector>
using namespace std;

int sumArray[10001];

int main() {
	int n, d;
	vector<int> numbers{ 0 };

	cin >> n;

	for ( int i = 1; i <= n; i++ )
	{
		cin >> d;

		numbers.push_back( d );

		if ( i != 1 ) {
			sumArray[i] = numbers[i] + sumArray[i - 1];
		}
		else {
			sumArray[i] = d;
		}
	}

	int m;

	cin >> m;

	for ( int i = 1; i <= m; i++ )
	{
		int a, b, sum = 0;

		cin >> a >> b;

		sum = sumArray[b] - sumArray[a - 1];

		cout << sum << endl;
	}

	return 0;
}