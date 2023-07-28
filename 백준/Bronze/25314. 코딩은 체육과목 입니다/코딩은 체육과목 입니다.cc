#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);

	int N;

	cin >> N;

	for (int i = 0; i < N / 4; i++)
	{
		cout << "long" << " ";
	}
	cout << "int" << '\n';

	return 0;
}