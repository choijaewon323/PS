#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10000
#define INF 100000000

vector<int> preorder;

void input() 
{
	while (true)
	{
		int temp;
		
		cin >> temp;
		if (cin.eof())
		{
			break;
		}
		preorder.push_back(temp);
	}
}

int findLeftIndex(const int start, const int end, const int root)
{
	for (int i = start + 1; i < end; i++)
	{
		if (preorder[i] < root)
		{
			return i;
		}
	}

	return end;
}

int findRightIndex(const int start, const int end, const int root)
{
	for (int i = start + 1; i < end; i++)
	{
		if (preorder[i] > root)
		{
			return i;
		}
	}

	return end;
}

void toOridinal(const int index, const int start, const int end)
{	
	const int root = preorder[start];
	const int leftIndex = findLeftIndex(start, end, root);
	const int rightIndex = findRightIndex(start, end, root);

	if (leftIndex < end)
	{
		toOridinal(index * 2, leftIndex, rightIndex);
	}
	
	if (rightIndex < end)
	{
		toOridinal(index * 2 + 1, rightIndex, end);
	}

	cout << root << '\n';
}



int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	toOridinal(1, 0, preorder.size());

	return 0;
}