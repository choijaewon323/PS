#include <iostream>
#include <string>
using namespace std;

typedef struct node
{
	int number;
	struct node* nextNode = 0;
} Node;

class List
{
private:
	Node* frontNode = 0;
	Node* backNode = 0;

public:
	void addFront(Node* node)
	{
		if(frontNode == 0)
		{
			frontNode = node;
			backNode = node;
		}
		else
		{
			Node* temp = frontNode;

			frontNode = node;
			frontNode->nextNode = temp;
		}
	}
	void removeFront()
	{
		if(frontNode == 0)
		{
			cout << -1 << '\n';
		}
		else
		{
			Node* temp = frontNode;
			frontNode = frontNode->nextNode;
			cout << temp->number << '\n';
			delete temp;
		}
	}
	void front()
	{
		if(frontNode == 0)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << frontNode->number << '\n';
		}
	}
	void empty()
	{
		if(frontNode == 0)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}
	void showList()
	{
		if(frontNode == 0) 
		{
			cout << -1 << '\n';
		}
		else
		{
			Node* temp = frontNode;
			while(temp != 0)
			{
				cout << temp->number << " ";
				temp = temp->nextNode;
			}
			cout << '\n';
		}
	}
	void addBack(Node* node)
	{
		if(backNode == 0)
		{
			frontNode = node;
			backNode = node;
		}
		else
		{
			Node* temp = backNode;
			backNode = node;
			temp->nextNode = backNode;
		}
	}
};

int main()
{
	int n, x;
	string command;
	List list;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> command;

		if(command == "addFront")
		{
			cin >> x;
			Node* node = new Node;
			node->number = x;
			list.addFront(node);
		}
		else if(command == "removeFront")
		{
			list.removeFront();
		}
		else if(command == "front")
		{
			list.front();
		}
		else if(command == "empty")
		{
			list.empty();
		}
		else if(command == "showList")
		{
			list.showList();
		}
		else
		{
			cin >> x;
			Node* node = new Node;
			node->number = x;
			list.addBack(node);
		}
	}

	return 0;
}