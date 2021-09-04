#include <iostream>
#include <vector>
using namespace std;

typedef struct node {
	int data;
	struct node* prevNode = 0;
	struct node* nextNode = 0;
} Node;

class queue{
private:
	Node* front = 0;
	Node* rear = 0;

public:
	void push(Node* element) {
		if(front == 0) {
			front = element;
			rear = element;
			element->nextNode = element;
			element->prevNode = element;
		}
		else {
			Node* temp = rear;
			rear = element;
			temp->nextNode = rear;
			rear->prevNode = temp;
			rear->nextNode = front;
			front->prevNode = rear;
		}
	}
	void pop() {
		if(front == 0) return;
		Node* temp = front;
		front = front->nextNode;

		temp->prevNode->nextNode = front;
		front->prevNode = temp->prevNode;

		delete temp;
	}
	Node* frontElement() {
		if(front == 0) return 0;
		else return front;
	}
	void moveLeft() {
		front = front->nextNode;
		rear = rear->nextNode;
	}
	void moveRight() {
		front = front->prevNode;
		rear = rear->prevNode;
	}
};

int minOperation(queue& q, int m) {
	int nL = 0, nR = 0;
	queue temp = q;

	while(m != temp.frontElement()->data) {
		nL++;
		temp.moveLeft();
	}

	queue temp1 = q;

	while(m != temp1.frontElement()->data) {
		nR++;
		temp1.moveRight();
	}
	
	if(nL > nR) {
		for(int i = 0; i < nR; i++)
		{
			q.moveRight();
		}
		q.pop();
		return nR;
	}
	else {
		for(int i = 0; i < nL; i++)
		{
			q.moveLeft();
		}
		q.pop();
		return nL;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	vector<int> numbers;

	cin >> n >> m;

	queue q;

	for(int i = 1; i <= n; i++) {
		Node* temp = new Node;

		temp->data = i;
		q.push(temp);
	}

	for(int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}

	int result = 0;

	for(int element : numbers) {
		result += minOperation(q, element);
	}
	cout << result << endl;

	return 0;
}