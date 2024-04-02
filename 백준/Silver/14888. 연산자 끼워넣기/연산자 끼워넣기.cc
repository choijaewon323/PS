#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 11
#define PLUS 0
#define MINUS 1
#define MUL 2
#define DIV 3
#define MAX_INIT -1000000001
#define MIN_INIT 1000000001

int N;
int A[MAX];
vector<int> oper;
vector<bool> visited;
int maxAnswer;
int minAnswer;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		int temp;
		cin >> temp;
		
		for (int j = 0; j < temp; j++) {
			oper.push_back(i);
		}
	}
}

void solve(vector<int> &tempOper) {
	if (tempOper.size() == N - 1) {
		int result = A[0];

		for (int i = 1; i < N; i++) {
			int presentOper = tempOper[i - 1];
			
			if (presentOper == PLUS) {
				result += A[i];
			} else if (presentOper == MINUS) {
				result -= A[i];
			} else if (presentOper == MUL) {
				result *= A[i];
			} else if (presentOper == DIV) {
				result /= A[i];
			}
		}

		maxAnswer = max(maxAnswer, result);
		minAnswer = min(minAnswer, result);

		return;
	}

	for (int i = 0; i < N - 1; i++) {
		if (!visited[i]) {
			visited[i] = true;
			tempOper.push_back(oper[i]);
			solve(tempOper);
			tempOper.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	visited = vector<bool>(N, false);
	maxAnswer = MAX_INIT;
	minAnswer = MIN_INIT;
	vector<int> tempOper;
	solve(tempOper);

	cout << maxAnswer << '\n';
	cout << minAnswer << '\n';
	
	return 0;
}