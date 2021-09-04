#include <iostream>
using namespace std;

typedef struct node {
	int data;
	struct node* nextNode = 0;
} Node;

class queue {
private:
	Node* q = 0;
	Node* frontIndex = 0;
	Node* rear = 0;
	int qSize = 0;

public:
	void push(Node* element) {
		if(q == 0) {
			q = element;
			frontIndex = element;
			rear = element;
			qSize++;
		}
		else {
			q->nextNode = element;
			q = element;
			rear = element;
			qSize++;
		}
	}

	void pop() {
		if(q == 0) return;
		else {
			Node* temp = frontIndex;
			frontIndex = frontIndex->nextNode;
			delete temp;
			qSize--;
		}
	}

	int size() {
		return qSize;
	}

	Node* front() {
		return frontIndex;
	}
};

int main() {
	int n;
	queue q;

	cin >> n;

	for(int i = 0; i < n; i++) {
		Node* temp = new Node;
		temp->data = i + 1;
		q.push(temp);
	}

	if(q.size() == 1) {
		cout << 1 << endl;
		return 0;
	}

	q.pop();

	while(q.size() != 1) {
		Node* temp = q.front();
		Node* temp1 = new Node;
		temp1->data = temp->data;
		q.pop();
		q.push(temp1);
		q.pop();
	}

	cout << q.front()->data << endl;

	return 0;
}