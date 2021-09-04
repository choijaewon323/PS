#include <iostream>
#include <vector>
using namespace std;

int main() {
	int k, num, result = 0;
	vector<int> numbers;

	cin >> k;

	for ( int i = 0; i < k; i++ )
	{
		cin >> num;

		if ( numbers.empty() && num == 0 ) {
			continue;
		}
		else if ( ( !numbers.empty() ) && num == 0 ) {
			numbers.pop_back();
		}
		else {
			numbers.push_back( num );
		}		
	}
	
	for ( int element : numbers ) {
		result += element;
	}

	cout << result << endl;

	return 0;
}