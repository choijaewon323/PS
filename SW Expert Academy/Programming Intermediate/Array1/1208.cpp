#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	int test_case;
	int T;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		vector<int> arr(100);
		int dump;
		int height;

		cin >> dump;

		for (int i = 0; i < 100; i++)
		{
			cin >> height;
			arr[i] = height;
		}

		for (int i = 0; i < dump; i++)
		{
			sort(arr.begin(), arr.end());

			arr[0]++;
			arr[99]--;
		}

		sort(arr.begin(), arr.end());
		cout << "#" << test_case << " " << arr[99] - arr[0] << '\n';
	}
	return 0;
}