#include <iostream>
#include <string>
#include <utility>
using namespace std;

pair<int, int> locOfKing;
pair<int, int> locOfStone;

bool isOut(int y, int x) {
	if (y >= 9 || y <= 0) {
		return true;
	}
	if (x >= 9 || x <= 0) {
		return true;
	}
	return false;
}

void move(string command) {
	int tempKingY = locOfKing.first;
	int tempKingX = locOfKing.second;
	int tempStoneY = locOfStone.first;
	int tempStoneX = locOfStone.second;

	if (command == "R") {
		tempKingX++;
		
		if (tempStoneY == tempKingY && tempStoneX == tempKingX) {
			tempStoneX++;
		}
	}
	else if (command == "L") {
		tempKingX--;

		if (tempStoneY == tempKingY && tempStoneX == tempKingX) {
			tempStoneX--;
		}
	}
	else if (command == "B") {
		tempKingY++;

		if (tempStoneY == tempKingY && tempStoneX == tempKingX) {
			tempStoneY++;
		}
	}
	else if (command == "T") {
		tempKingY--;

		if (tempStoneY == tempKingY && tempStoneX == tempKingX) {
			tempStoneY--;
		}
	}
	else if (command == "RT") {
		tempKingY--;
		tempKingX++;

		if (tempStoneY == tempKingY && tempStoneX == tempKingX) {
			tempStoneY--;
			tempStoneX++;
		}
	}
	else if (command == "LT") {
		tempKingY--;
		tempKingX--;

		if (tempStoneY == tempKingY && tempStoneX == tempKingX) {
			tempStoneY--;
			tempStoneX--;
		}
	}
	else if (command == "RB") {
		tempKingY++;
		tempKingX++;

		if (tempStoneY == tempKingY && tempStoneX == tempKingX) {
			tempStoneY++;
			tempStoneX++;
		}
	}
	else if (command == "LB") {
		tempKingY++;
		tempKingX--;

		if (tempStoneY == tempKingY && tempStoneX == tempKingX) {
			tempStoneY++;
			tempStoneX--;
		}
	}

	if (isOut(tempKingY, tempKingX)) {
		return;
	}
	if (isOut(tempStoneY, tempStoneX)) {
		return;
	}
	
	locOfKing.first = tempKingY;
	locOfKing.second = tempKingX;

	locOfStone.first = tempStoneY;
	locOfStone.second = tempStoneX;
}

string convertLoc(int y, int x) {
	string answer = "";
	
	char column = 'A' + (x - 1);
	answer += column;
	
	char row = (9 - y) + '0';
	answer += row;

	return answer;
}

int main() {
	string king, stone;
	int n;
	
	cin >> king >> stone >> n;

	int y = 9 - (king[1] - '0');
	int x = (king[0] - 'A') + 1;
	locOfKing.first = y;
	locOfKing.second = x;

	y = 9 - (stone[1] - '0');
	x = (stone[0] - 'A') + 1;
	locOfStone.first = y;
	locOfStone.second = x;

	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		move(command);
	}
	
	cout << convertLoc(locOfKing.first, locOfKing.second) << '\n'
		<< convertLoc(locOfStone.first, locOfStone.second) << '\n';

	return 0;
}