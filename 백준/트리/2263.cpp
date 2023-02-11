#include <iostream>
#include <queue>
using namespace std;

int inorder[100001];
int postorder[100001];
int inorderIndex[100001];

int n;

void preorder(int inStart, int inEnd, int postStart, int postEnd)
{
	if (inStart > inEnd || postStart > postEnd)
	{
		return;
	}

	// Root
	cout << postorder[postEnd] << " ";

	int index = inorderIndex[postorder[postEnd]];
	int leftCount = index - inStart;

	// L
	preorder(inStart, index - 1, postStart, postStart + leftCount - 1);

	// R
	preorder(index + 1, inEnd, postStart + leftCount, postEnd - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		inorder[i] = temp;
		inorderIndex[temp] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		postorder[i] = temp;
	}

	preorder(1, n, 1, n);
	cout << '\n';

	return 0;
}