#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, d;
	vector<int> numbers;

	cin >> n;
	
	for ( int i = 0; i < n; i++ )
	{
		cin >> d;

		numbers.push_back( d );
	}

	int m;

	cin >> m;

	for ( int i = 0; i < m; i++ )
	{
		int a, b, sum = 0;

		cin >> a >> b;

		for ( int j = a - 1; j < b; j++ )
		{
			sum += numbers[j];
		}

		cout << sum << endl;
	}

	return 0;
}