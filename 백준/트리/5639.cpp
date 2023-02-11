#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int preorder[10003];

void postorder(int preStart, int preEnd)
{
	if (preStart > preEnd)
	{
		return;
	}
	if (preStart == preEnd)
	{
		cout << preorder[preStart] << '\n';
		return;
	}

	int root = preorder[preStart];
	int temp = preEnd;

	for (int i = preStart + 1; i <= preEnd; i++)
	{
		if (preorder[i] > root)
		{
			temp = i - 1;
			break;
		}
	}

	// L
	postorder(preStart + 1, temp);

	// R
	postorder(temp + 1, preEnd);

	cout << root << '\n';
}

int main()
{
	int i = 1;
	int temp;

	while (1)
	{
		cin >> temp;
		preorder[i] = temp;
		i++;

		if (cin.eof())
		{
			break;
		}
	}

	postorder(1, i - 2);

	return 0;
}