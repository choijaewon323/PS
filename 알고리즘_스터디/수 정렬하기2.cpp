#include <iostream>
using namespace std;

int* numbers;
int* temp;
int n;

void merge(int low, int mid, int high)
{
	int left = low, right = mid + 1, index = left;

	while(left <= mid && right <= high)
	{
		if(numbers[left] > numbers[right])
		{
			temp[index] = numbers[right];
			right++;
		}
		else
		{
			temp[index] = numbers[left];
			left++;
		}
		index++;
	}

	if(left > mid)
	{
		for(int i = right; i <= high; i++)
		{
			temp[index] = numbers[i];
			index++;
		}
	}
	else
	{
		for(int i = left; i <= mid; i++)
		{
			temp[index] = numbers[i];
			index++;
		}
	}

	for(int i = low; i <= high; i++)
	{
		numbers[i] = temp[i];
	}
}

void merge_sort(int low, int high)
{
	int mid = (low + high) / 2;

	if(low < high)
	{
		merge_sort(low, mid);
		merge_sort(mid + 1, high);

		merge(low, mid, high);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	numbers = new int[n];
	temp = new int[n];

	for(int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	merge_sort(0, n - 1);

	for(int i = 0; i < n; i++)
	{
		 cout << numbers[i] << '\n';
	}

	delete[] numbers;
	delete[] temp;

	return 0;
}