#include <iostream>
#include <vector>
using namespace std;

typedef struct node
{
	int nodeNumber;
	vector<struct node*> children;
} Node;

void search(Node* node, int index)
{
	if(node == 0) return;
	if(node->nodeNumber == index)
	{
		if(node->children.empty())
		{
			cout << 0 << '\n';
		}
		else
		{
			for(auto element : node->children)
			{
				cout << element->nodeNumber << " ";
			}
			cout << '\n';
		}
	}
	for(auto element : node->children)
	{
		search(element, index);
	}
}

int main()
{
	int n, m, index, child;
	vector<Node*> nodes;
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
		Node* node = new Node;
		node->nodeNumber = i;
		nodes.push_back(node);
	}

	for(int i = 0; i < n; i++)
	{
		cin >> index;

		cin >> child;
		while(child != 0)
		{
			nodes[index - 1]->children.push_back(nodes[child - 1]);
			cin >> child;
		}
	}

	for(int i = 0; i < m; i++)
	{
		cin >> index;

		search(nodes[0], index);
	}

	return 0;
}