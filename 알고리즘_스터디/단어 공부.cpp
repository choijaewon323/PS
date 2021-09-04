#include <iostream>
#include <string>
using namespace std;

int arr[26];

void count( char element );

int main() {
	string word;
	int maximum = 0;
	int maximumIndex;

	cin >> word;

	for ( char element : word )
	{
		count( element );
	}

	for ( int i = 0; i < 26; i++ )
	{
		if ( maximum < arr[i] ) {
			maximum = arr[i];
			maximumIndex = i;
		}
	}

	for ( int i = 0; i < 26; i++ )
	{
		if ( maximum == arr[i] && maximumIndex != i ) {
			maximumIndex = -1;
			break;
		}
	}

	if ( maximumIndex == -1 ) {
		cout << "?" << endl;
	}
	else {
		cout << (char)( maximumIndex + 'A' ) << endl;
	}

	return 0;
}

void count( char element ) {
	if ( element >= 'a' && element <= 'z' ) {
		arr[element - 'a']++;
	}
	else {
		arr[element - 'A']++;
	}
}