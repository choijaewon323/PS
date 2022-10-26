#include <iostream>
#include <vector>
using namespace std;

typedef struct man {
	int wgt;
	int hgt;
	int num;
} Man;

int main() {
	int n;
	vector<Man*> arr;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int w, h;
		cin >> w >> h;
		Man* temp = new Man;
		temp->wgt = w;
		temp->hgt = h;
		temp->num = 1;
		arr.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}
			if (arr[i]->wgt > arr[j]->wgt && arr[i]->hgt > arr[j]->hgt)
			{
				(arr[j]->num)++;
			}
		}
	}
	for (auto element : arr)
	{
		cout << element->num << " ";
		delete element;
	}
	cout << '\n';
	return 0;
}