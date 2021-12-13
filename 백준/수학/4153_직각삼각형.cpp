#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long square(long long num)
{
	return num * num;
}
int main()
{
	int n1, n2, n3;
	while (true)
	{
		vector<int> arr;
		cin >> n1 >> n2 >> n3;
		if (n1 == 0 && n2 == 0 && n3 == 0)
		{
			break;
		}
		arr.push_back(n1);
		arr.push_back(n2);
		arr.push_back(n3);
		sort(arr.begin(), arr.end());
		if (square(arr[2]) == square(arr[0]) + square(arr[1]))
		{
			cout << "right" << '\n';
		}
		else
		{
			cout << "wrong" << '\n';
		}
	}
	return 0;
}