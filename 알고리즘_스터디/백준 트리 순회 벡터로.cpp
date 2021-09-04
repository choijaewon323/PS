#include <iostream>
using namespace std;
char nodes[26][3];
void preorder(char node[3])
{
	cout << node[0];
	if(node[1]) preorder(nodes[node[1] - 'A']);
	if(node[2]) preorder(nodes[node[2] - 'A']);
}
void inorder(char node[3])
{
	if(node[1]) inorder(nodes[node[1] - 'A']);
	cout << node[0];
	if(node[2]) inorder(nodes[node[2] - 'A']);
}
void postorder(char node[2])
{
	if(node[1]) postorder(nodes[node[1] - 'A']);
	if(node[2]) postorder(nodes[node[2] - 'A']);
	cout << node[0];
}
int main()
{
	int n;
	char node, left, right;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> node >> left >> right;
		nodes[node - 'A'][0] = node;
		if(left != '.') nodes[node - 'A'][1] = left;
		if(right != '.') nodes[node - 'A'][2] = right;
	}
	preorder(nodes[0]);
	cout << '\n';
	inorder(nodes[0]);
	cout << '\n';
	postorder(nodes[0]);
	cout << '\n';
	return 0;
}