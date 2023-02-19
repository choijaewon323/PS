#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int arr[1000001];
int index[1000001];
int n;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		if (v.empty() || v[v.size() - 1] < arr[i])
		{
			v.push_back(arr[i]);
			index[i] = v.size() - 1;
		}
		else
		{
			int temp = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[temp] = arr[i];
			index[i] = temp;
		}
	}

	cout << v.size() << '\n';
	vector<int> result;
	int resultIndex = v.size() - 1;

	for (int i = n; i >= 1; i--)
	{
		if (index[i] == resultIndex)
		{
			resultIndex--;
			result.push_back(arr[i]);
		}
	}

	for (int i = result.size() - 1; i >= 0; i--)
	{
		cout << result[i] << " ";
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	input();
	solution();

	return 0;
}