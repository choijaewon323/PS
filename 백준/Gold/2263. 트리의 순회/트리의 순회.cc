#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 100000

int n;
int inorder[MAX]; // 왼루오
int postorder[MAX]; // 왼오루

int findRootIndex(int start, int end, int root) {
	for (int i = start; i <= end; i++) {
		if (inorder[i] == root) {
			return i;
		}
	}
	return -1;
}

void preorder(int start, int end, int left, int right) {
	if (start > end || left > right) {
		return;
	}
	
	int root = postorder[right];
	int rootIndex = findRootIndex(start, end, root);

	int leftSize = rootIndex - start;

	cout << root << " ";
	preorder(start, rootIndex - 1, left, left + leftSize - 1);
	preorder(rootIndex + 1, end, left + leftSize, right - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}

	preorder(0, n - 1, 0, n - 1);

	return 0;
}