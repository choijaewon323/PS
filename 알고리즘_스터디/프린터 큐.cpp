#include <iostream>
using namespace std;

#define MAX 10000

typedef struct node {
	int index;
	int importance;
} Node;

class queue {
private:
	Node* arr[MAX] = {0};
	int frontIndex = 0;
	int rear = 0;

public:
	void push(Node* element) {
		if(rear == MAX) return;
		arr[rear++] = element;
	}

	void pop() {
		if(frontIndex == rear) return;
		frontIndex++;
	}

	bool empty() {
		if(frontIndex == rear)return true;
		else return false;
	}

	Node* front() {
		if(frontIndex == rear) return 0;
		else return arr[frontIndex];
	}

	Node* back() {
		if(frontIndex == rear) return 0;
		else return arr[rear - 1];
	}

	int mostImp() {
		int imp = 0;

		for(int i = frontIndex; i < rear; i++) {
			if((arr[i]->importance) > imp) imp = arr[i]->importance;
		}

		return imp;
	}
};

Node* print(queue& q) {
	int imp = q.mostImp();
	Node* temp = q.front();

	while(imp != temp->importance) {
		q.pop();
		q.push(temp);
		temp = q.front();
	}
	q.pop();
	return temp;
}

int findDoc(queue& q, int m) {
	Node* temp = print(q);
	int n = 1;

	while(m != temp->index) {
		temp = print(q);
		n++;
	}
	return n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int testCase;

	cin >> testCase;

	for(int i = 0; i < testCase; i++) {
		int n, m;
		queue q;

		cin >> n >> m;

		for(int j = 0; j < n; j++) {
			Node* temp = new Node;
			int imp;
			cin >> imp;
			temp->index = j;
			temp->importance = imp;
			q.push(temp);
		}
		cout << findDoc(q, m) << endl;

		while(!q.empty()) {
			q.pop();
		}
	}

	return 0;
}