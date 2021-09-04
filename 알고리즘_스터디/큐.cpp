#include <iostream>
#include <string>
using namespace std;

#define MAX 10000

class queue {
private:
	int arr[MAX] = {0};
	int frontIndex = 0;
	int rear = 0;

public:
	void push(int element) {
		if((rear - frontIndex) == MAX) return;
		arr[rear++] = element;
	}

	int pop() {
		if(frontIndex == rear) return -1;
		return arr[frontIndex++];
	}

	int size() {
		return rear - frontIndex;
	}

	bool empty() {
		if(frontIndex == rear) return true;
		else return false;
	}

	int front() {
		if(frontIndex == rear) return -1;
		else return arr[frontIndex];
	}

	int back() {
		if(frontIndex == rear) return - 1;
		else return arr[rear - 1];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string command;
	queue q;

	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> command;

		if(command == "push") {
			int operand;
			cin >> operand;
			q.push(operand);
		}
		else if(command == "pop") cout << q.pop() << endl;
		else if(command == "size") cout << q.size() << endl;
		else if(command == "empty") cout << q.empty() << endl;
		else if(command == "front") cout << q.front() << endl;
		else if(command == "back") cout << q.back() << endl;
	}

	return 0;
}