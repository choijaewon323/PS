#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<int> st;
	int number;
	int x;
	string command;

	cin >> number;

	for ( int i = 0; i < number; i++ )
	{  
		cin >> command;

		if ( command == "push" ) {
			cin >> x;

			st.push( x );
		}
		else if ( command == "pop" )
		{
			if ( st.empty() ) {
				cout << -1 << endl;
			}
			else {
				cout << st.top() << endl;

				st.pop();
			}
		}
		else if ( command == "size" )
		{
			cout << st.size() << endl;
		}
		else if (command == "empty" )
		{
			cout << st.empty() << endl;
		}
		else if ( command == "top" ) {
			if ( st.empty() ) {
				cout << -1 << endl;
			}
			else {
				cout << st.top() << endl;
			}
		}
	}

	return 0;
}