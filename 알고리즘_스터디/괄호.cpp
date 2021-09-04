#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool judge( string& ps ) {
	stack<char> st;
	
	for ( char element : ps ) {
		if ( st.empty() && element == ')' ) {
			return false;
		}

		if ( element == '(' ) {
			st.push( '(' );
		}
		else {
			st.pop();
		}
	}

	if ( st.empty() ) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int t;
	string ps;

	cin >> t;

	for ( int i = 0; i < t; i++ )
	{
		cin >> ps;

		if ( judge( ps ) ) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}