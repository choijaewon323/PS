#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	vector<int> arr;
	vector<int> res;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				int temp = arr[i] + arr[j] + arr[k];
				res.push_back(temp);
			}
		}
	}
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] > m)
		{
			res[i] = 0;
		}
	}
	sort(res.begin(), res.end());
	cout << res.back() << '\n';
	return 0;
}