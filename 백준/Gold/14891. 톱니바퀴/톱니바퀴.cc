#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define CLOCK 1
#define COUNTERCLOCK -1
#define NOT 0
#define UP 0
#define RIGHT 2
#define LEFT 6

vector<int> gear[4];

void clock(int gearNum) {
	vector<int> result;
	
	result.push_back(gear[gearNum][7]);
	
	for (int i = 0; i <= 6; i++) {
		result.push_back(gear[gearNum][i]);
	}

	gear[gearNum] = result;
}

void counterClock(int gearNum) {
	vector<int> result;

	for (int i = 1; i <= 7; i++) {
		result.push_back(gear[gearNum][i]);
	}
	result.push_back(gear[gearNum][0]);

	gear[gearNum] = result;
}

int calculate() {
	int result = 0;
	
	if (gear[0][UP] == 1) {
		result += 1;
	}

	if (gear[1][UP] == 1) {
		result += 2;
	}

	if (gear[2][UP] == 1) {
		result += 4;
	}

	if (gear[3][UP] == 1) {
		result += 8;
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			char c;
			cin >> c;
			
			gear[i].push_back(c - '0');
		}
	}

	int K;
	cin >> K;
	
	for (int i = 0; i < K; i++) {
		int num, direct;
		cin >> num >> direct;

		num--;
		
		int rotation[4] = { NOT, NOT, NOT, NOT };
		rotation[num] = direct;

		// check left
		for (int i = num - 1; i >= 0; i--) {
			int prevIndex = i + 1;
			int prevLeft = gear[prevIndex][LEFT];
			int myRight = gear[i][RIGHT];

			if (prevLeft != myRight) {
				if (rotation[prevIndex] == CLOCK) {
					rotation[i] = COUNTERCLOCK;
				} else if (rotation[prevIndex] == COUNTERCLOCK) {
					rotation[i] = CLOCK;
				}
			}
		}

		// check right
		for (int i = num + 1; i < 4; i++) {
			int prevIndex = i - 1;
			int prevRight = gear[prevIndex][RIGHT];
			int myLeft = gear[i][LEFT];

			if (prevRight != myLeft) {
				if (rotation[prevIndex] == CLOCK) {
					rotation[i] = COUNTERCLOCK;
				} else if (rotation[prevIndex] == COUNTERCLOCK) {
					rotation[i] = CLOCK;
				}
			}
		}

		// rotation
		for (int i = 0; i < 4; i++) {
			if (rotation[i] == CLOCK) {
				clock(i);
			} else if (rotation[i] == COUNTERCLOCK) {
				counterClock(i);
			}
		}
	}

	cout << calculate() << '\n';

	return 0;
}