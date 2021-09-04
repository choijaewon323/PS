#include <iostream>
using namespace std;

typedef struct node
{
	char data;
	struct node* left = 0;
	struct node* right = 0;
} Node;

Node nodes[26];

void preorder(Node* node)
{
	if(node == 0) return;
	cout << node->data;
	preorder(node->left);
	preorder(node->right);
}

void inorder(Node* node)
{
	if(node == 0) return;
	inorder(node->left);
	cout << node->data;
	inorder(node->right);
}

void postorder(Node* node)
{
	if(node == 0) return;
	postorder(node->left);
	postorder(node->right);
	cout << node->data;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	char c, left, right;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> c >> left >> right;

		nodes[c - 'A'].data = c;
		if(left != '.') nodes[c - 'A'].left = &nodes[left - 'A'];
		if(right != '.') nodes[c - 'A'].right = &nodes[right - 'A'];
	}

	preorder(&nodes[0]);
	cout << '\n';
	inorder(&nodes[0]);
	cout << '\n';
	postorder(&nodes[0]);
	cout << '\n';

	return 0;
}