#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
void output(vector<vector<int>>& input) {
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input[i].size(); j++) {
			cout << input[i][j] << " ";
		}
		cout << '\n';
	}
}
void oper1(vector<vector<int>>& input) {
	vector<vector<int>> temp;
	int count = 0;
	for (int i = input.size() - 1; i >= 0; i--) {
		vector<int> t;
		temp.push_back(t);
		for (int j = 0; j < input[i].size(); j++) {
			temp[count].push_back(input[i][j]);
		}
		count++;
	}
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input[i].size(); j++) {
			input[i][j] = temp[i][j];
		}
	}
}
void oper2(vector<vector<int>>& input) {
	for (int i = 0; i < input.size(); i++) {
		reverse(input[i].begin(), input[i].end());
	}
}
vector<vector<int>> oper3(vector<vector<int>>& input) {
	vector<vector<int>> result;
	int count = 0;
	for (int i = 0; i < input.front().size(); i++) {
		vector<int> temp;
		result.push_back(temp);
		for (int j = input.size() - 1; j >= 0; j--) {
			result[count].push_back(input[j][i]);
		}
		count++;
	}
	return result;
}
vector<vector<int>> oper4(vector<vector<int>>& input) {
	vector<vector<int>> result;
	int count = 0;
	for (int i = input.front().size() - 1; i >= 0; i--) {
		vector<int> temp;
		result.push_back(temp);
		for (int j = 0; j < input.size(); j++) {
			result[count].push_back(input[j][i]);
		}
		count++;
	}
	return result;
}
vector<vector<int>> slice(vector<vector<int>>& input,
	int startY, int startX, int endY, int endX) {
	vector<vector<int>> result;
	int count = 0;
	for (int i = startY; i <= endY; i++) {
		vector<int> temp;
		result.push_back(temp);
		for (int j = startX; j <= endX; j++) {
			result[count].push_back(input[i][j]);
		}
		count++;
	}
	return result;
}
void oper5(vector<vector<int>>& input) {
	vector<vector<int>> part1 = slice(input,
		0, 0, input.size() / 2 - 1, input.front().size() / 2 - 1
	);
	vector<vector<int>> part2 = slice(input,
		0, input.front().size() / 2, input.size() / 2 - 1, input.front().size() - 1
	);
	vector<vector<int>> part3 = slice(input,
		input.size() / 2, input.front().size() / 2, input.size() - 1, input.front().size() - 1
	);
	vector<vector<int>> part4 = slice(input,
		input.size() / 2, 0, input.size() - 1, input.front().size() / 2 - 1
	);
	int countY = 0;
	int countX = 0;
	// 1
	for (int i = 0; i < input.size() / 2; i++) {
		for (int j = 0; j < input.front().size() / 2; j++) {
			input[i][j] = part4[countY][countX];
			countX++;
		}
		countY++;
		countX = 0;
	}
	countY = 0;
	countX = 0;
	// 2
	for (int i = 0; i < input.size() / 2; i++) {
		for (int j = input.front().size() / 2; j < input.front().size(); j++) {
			input[i][j] = part1[countY][countX];
			countX++;
		}
		countY++;
		countX = 0;
	}
	countY = 0;
	countX = 0;
	// 4
	for (int i = input.size() / 2; i < input.size(); i++) {
		for (int j = 0; j < input.front().size() / 2; j++) {
			input[i][j] = part3[countY][countX];
			countX++;
		}
		countY++;
		countX = 0;
	}
	countY = 0;
	countX = 0;
	// 3
	for (int i = input.size() / 2; i < input.size(); i++) {
		for (int j = input.front().size() / 2; j < input.front().size(); j++) {
			input[i][j] = part2[countY][countX];
			countX++;
		}
		countY++;
		countX = 0;
	}
}
void oper6(vector<vector<int>>& input) {
	vector<vector<int>> part1 = slice(input,
		0, 0, input.size() / 2 - 1, input.front().size() / 2 - 1
	);
	vector<vector<int>> part2 = slice(input,
		0, input.front().size() / 2, input.size() / 2 - 1, input.front().size() - 1
	);
	vector<vector<int>> part3 = slice(input,
		input.size() / 2, input.front().size() / 2, input.size() - 1, input.front().size() - 1
	);
	vector<vector<int>> part4 = slice(input,
		input.size() / 2, 0, input.size() - 1, input.front().size() / 2 - 1
	);
	int countY = 0;
	int countX = 0;
	// 1
	for (int i = 0; i < input.size() / 2; i++) {
		for (int j = 0; j < input.front().size() / 2; j++) {
			input[i][j] = part2[countY][countX];
			countX++;
		}
		countY++;
		countX = 0;
	}
	countY = 0;
	countX = 0;
	// 2
	for (int i = 0; i < input.size() / 2; i++) {
		for (int j = input.front().size() / 2; j < input.front().size(); j++) {
			input[i][j] = part3[countY][countX];
			countX++;
		}
		countY++;
		countX = 0;
	}
	countY = 0;
	countX = 0;
	// 4
	for (int i = input.size() / 2; i < input.size(); i++) {
		for (int j = 0; j < input.front().size() / 2; j++) {
			input[i][j] = part1[countY][countX];
			countX++;
		}
		countY++;
		countX = 0;
	}
	countY = 0;
	countX = 0;
	// 3
	for (int i = input.size() / 2; i < input.size(); i++) {
		for (int j = input.front().size() / 2; j < input.front().size(); j++) {
			input[i][j] = part4[countY][countX];
			countX++;
		}
		countY++;
		countX = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<vector<int>> input;
	int r;
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		input.push_back(temp);
		for (int j = 0; j < m; j++) {
			int inputNum;
			cin >> inputNum;
			input[i].push_back(inputNum);
		}
	}
	for (int i = 0; i < r; i++) {
		int oper;
		cin >> oper;
		if (oper == 1) {
			oper1(input);
		}
		else if (oper == 2) {
			oper2(input);
		}
		else if (oper == 3) {
			vector<vector<int>> temp = oper3(input);
			input.clear();
			for (int i = 0; i < temp.size(); i++) {
				vector<int> t;
				input.push_back(t);
				for (int j = 0; j < temp[i].size(); j++) {
					input[i].push_back(temp[i][j]);
				}
			}
		}
		else if (oper == 4) {
			vector<vector<int>> temp = oper4(input);
			input.clear();
			for (int i = 0; i < temp.size(); i++) {
				vector<int> t;
				input.push_back(t);
				for (int j = 0; j < temp[i].size(); j++) {
					input[i].push_back(temp[i][j]);
				}
			}
		}
		else if (oper == 5) {
			oper5(input);
		}
		else if (oper == 6) {
			oper6(input);
		}
	}
	output(input);
	return 0;
}