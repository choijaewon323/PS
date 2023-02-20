#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[1000000];
vector<int> v;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (v.empty())
		{
			v.push_back(arr[i]);
			continue;
		}

		if (v.back() < arr[i])
		{
			v.push_back(arr[i]);
			continue;
		}

		int index = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
		
		v[index] = arr[i];
	}

	cout << v.size() << '\n';
}

int main()
{
	input();
	solution();

	return 0;
}