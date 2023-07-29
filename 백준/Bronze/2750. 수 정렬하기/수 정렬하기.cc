#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void selection_sort(vector<int> &arr)
{
	int minIndex = -1;

	for (int i = 0; i < arr.size(); i++)
	{
		minIndex = i;
		
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[minIndex] > arr[j])
			{
				minIndex = j;
			}
		}

		swap(arr[i], arr[minIndex]);
	}
}

int main()
{
	vector<int> arr;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;

		cin >> temp;

		arr.push_back(temp);
	}

	selection_sort(arr);

	for (int a : arr)
	{
		cout << a << '\n';
	}

	return 0;
}