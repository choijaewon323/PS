#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<char>> output;

void draw(int y, int x, int height) {
	if (height == 3) {
		output[y][x] = '*';
		output[y + 1][x - 1] = '*';
		output[y + 1][x + 1] = '*';
		for (int i = x - 2; i <= x + 2; i++) {
			output[y + 2][i] = '*';
		}
		return;
	}

	int width = 2 * height - 1;
	draw(y, x, height / 2);
	// left
	draw(y + height / 2, x - height / 2, height / 2);
	// right
	draw(y + height / 2, x + height / 2, height / 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	output = vector<vector<char>>(N, vector<char>(2 * N - 1, ' '));
	int width = 2 * N - 1;
	draw(0, width / 2, N);

	int w = output[0].size();
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < w; x++) {
			cout << output[y][x];
		}
		cout << '\n';
	}
	
	return 0;
}