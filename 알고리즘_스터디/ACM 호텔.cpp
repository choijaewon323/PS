#include <iostream>
using namespace std;

void numberOfRoom( int h, int w, int room );

int main() {
	int testCase, h, w, room;

	cin >> testCase;

	for ( int i = 0; i < testCase; i++ )
	{
		cin >> h >> w >> room;

		numberOfRoom( h, w, room );
	}

	return 0;
}

void numberOfRoom( int h, int w, int room ) {
	int num = 0;
	int height, width, result;
	bool flag = false;

	for ( int i = 1; i <= w; i++ )
	{
		for ( int j = 1; j <= h; j++ )
		{
			num++;

			if ( num == room ) {
				flag = true;
				height = j;
				width = i;
				break;
			}
		}
		if ( flag )
			break;
	}
	result = ( height * 100 ) + width;

	cout << result << endl;
}