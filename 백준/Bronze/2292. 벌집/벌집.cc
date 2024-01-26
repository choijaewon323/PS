#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long N;
	cin >> N;

	if (N == 1)
	{
		cout << 1 << '\n';
		return 0;
	}

	N--;
	long long cnt = 1;
	long long temp = 6;
	while (N > 0)
	{
		N -= temp;
		temp += 6;
		cnt++;
	}

	cout << cnt << '\n';
	
	return 0;
}