#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	cout << arr[0] << " " << arr[n - 1] << '\n';

	return 0;
}

// 벡터와 소트 말고 비교로 직접 하는 게 더 빠를 것 같다.