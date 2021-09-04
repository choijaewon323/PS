#include <iostream>
#include <vector>
using namespace std;

typedef struct node
{
	int nodeNumber;
	vector<struct node*> children;
} Node;

void search(Node* node, int index, int depth)
{
	if(node == 0) return;
	if(node->nodeNumber == index)
	{
		cout << depth << '\n';
	}
	for(auto element : node->children)
	{
		search(element, index, depth + 1);
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

		search(nodes[0], index, 0);
	}

	return 0;
}