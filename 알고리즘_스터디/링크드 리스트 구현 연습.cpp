#include <iostream>
#include <string>
using namespace std;

typedef struct node {
	int data = 0;
	struct node* prevNode = 0;
} Node;

class List {
private:
	Node* firstNode = 0;
	Node* frontNode = 0;

public:
	void addFront( Node* x );
	void removeFront();
	void front();
	void empty();
};

void List::addFront( Node* x ) {
	if ( firstNode == 0 ) {
		firstNode = x;
		frontNode = x;
	}
	else {
		Node* next = firstNode;

		while ( next->prevNode != 0 )
		{
			next = next->prevNode;
		}

		next->prevNode = x;
		
		frontNode = x;
	}
}

void List::removeFront() {
	if ( firstNode == 0 ) {
		cout << -1 << endl;
	}
	else {
		Node* next = firstNode;

		while ( next->prevNode != frontNode )
		{
			next = next->prevNode;
		}

		cout << frontNode->data << endl;

		next->prevNode = 0;

		frontNode = next;
	}
}

void List::front() {
	if ( frontNode == 0 ) {
		cout << -1 << endl;
	}
	else {
		cout << frontNode->data << endl;
	}
}

void List::empty() {
	if ( firstNode == 0 ) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
}

int main() {
	int n, x;
	string command;
	List list;

	cin >> n;

	for ( int i = 0; i < n; i++ )
	{
		cin >> command;

		if ( command == "addFront" ) {
			cin >> x;

			Node* newNode = new Node;

			newNode->data = x;

			list.addFront( newNode );
		}
		else if ( command == "removeFront" ) {
			list.removeFront();
		}
		else if ( command == "front" ) {
			list.front();
		}
		else {
			list.empty();
		}
	}

	return 0;
}