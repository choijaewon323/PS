#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<int> router;
	int n, temp;
	cin >> n;

	while (true) {
		cin >> temp;

		if (temp == -1) {	// end of input
			break;
		}
		else if (temp == 0) {	// pop
			router.pop();
		}
		else {	// push
			if (router.size() == n) {
				continue;
			}
			else {
				router.push(temp);
			}
		}
	}

	if (router.empty()) {
		cout << "empty" << '\n';
	}
	else {
		while (!router.empty()) {
			temp = router.front();
			router.pop();
			cout << temp << " ";
		}
		cout << '\n';
	}

	return 0;
}