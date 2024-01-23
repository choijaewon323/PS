#include <iostream>
#include <map>
#include <utility>

using namespace std;

map<char, pair<char, char>> tree;
int N;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		
		tree[a] = { b, c };
	}
}

void preorder(const char start) {
	if (start == '.') {
		return;
	}
	cout << start;
	preorder(tree[start].first);
	preorder(tree[start].second);
}

void inorder(const char start) {
	if (start == '.') {
		return;
	}
	inorder(tree[start].first);
	cout << start;
	inorder(tree[start].second);
}

void postorder(const char start) {
	if (start == '.') {
		return;
	}
	postorder(tree[start].first);
	postorder(tree[start].second);
	cout << start;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	cout << '\n';

	return 0;
}