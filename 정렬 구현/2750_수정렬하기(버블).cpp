#include <iostream>
using namespace std;
int arr[1000];
void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}