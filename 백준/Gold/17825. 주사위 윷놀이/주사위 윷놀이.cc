#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define START 0
#define END 32
#define RED 2
#define BLUE 3

typedef struct _node
{
	int score;
	int redNext;
	int blueNext;
	int state;
} node;

typedef struct _horse
{
	int index;
	int score;
} horse;

node nodes[33];

void init()
{
	// start
	nodes[0] = { 0, 1, -1, START };

	// end
	nodes[32] = { 0, 32, -1, END };

	nodes[1] = { 2, 2,-1,RED };
	nodes[2] = { 4, 3,-1,RED };
	nodes[3] = { 6, 4,-1,RED };
	nodes[4] = { 8, 5,-1,RED };

	// blue 10
	nodes[5] = { 10, 6, 10, BLUE };

	nodes[6] = { 12, 7, -1, RED };
	nodes[7] = { 14, 8, -1, RED };
	nodes[8] = { 16, 9, -1, RED };
	nodes[9] = { 18, 13, -1, RED };

	nodes[10] = { 13, 11, -1, RED };
	nodes[11] = { 16, 12, -1, RED };
	nodes[12] = { 19, 24, -1, RED };

	// blue 20
	nodes[13] = { 20, 16, 14, BLUE };

	nodes[14] = { 22, 15, -1, RED };
	nodes[15] = { 24, 24, -1, RED };

	nodes[16] = { 22, 17, -1, RED };
	nodes[17] = { 24, 18, -1, RED };
	nodes[18] = { 26, 19, -1, RED };
	nodes[19] = { 28, 20, -1, RED };

	// blue 30
	nodes[20] = { 30, 25, 21, BLUE };

	nodes[21] = { 28, 22, -1, RED };
	nodes[22] = { 27, 23, -1, RED };
	nodes[23] = { 26, 24, -1, RED };

	nodes[25] = { 32, 26, -1, RED };
	nodes[26] = { 34, 27, -1, RED };
	nodes[27] = { 36, 28, -1, RED };
	nodes[28] = { 38, 31, -1, RED };

	// 25
	nodes[24] = { 25, 29, -1, RED };

	nodes[29] = { 30, 30, -1, RED };
	nodes[30] = { 35, 31, -1, RED };

	// 40
	nodes[31] = { 40, 32, -1, RED };
}

int move(horse present, int diceNum)
{
	horse result;

	int idx = present.index;
	int next;

	if (nodes[idx].state == BLUE)
	{
		next = nodes[idx].blueNext;

	}
	else
	{
		next = nodes[idx].redNext;
	}

	diceNum--;
	while (diceNum > 0)
	{
		next = nodes[next].redNext;
		diceNum--;
	}

	return next;
}

vector<int> dice;

bool isHorse[33];

int solution(int idx, vector<horse> horses)
{
	if (idx == dice.size())
	{
		// examine

		int answer = 0;
		for (int i = 0; i < 4; i++)
		{
			answer += horses[i].score;
		}

		return answer;
	}

	int result = -1000000000;
	for (int i = 0; i < 4; i++)
	{
		vector<horse> tempHorses = horses;
		if (tempHorses[i].index == 32)
		{
			continue;
		}
		
		int present = tempHorses[i].index;
		int next = move(tempHorses[i], dice[idx]);
		if (next == 32 || (next != 32 && !isHorse[next]))
		{
			isHorse[present] = false;
			isHorse[next] = true;
			tempHorses[i].index = next;
			tempHorses[i].score += nodes[next].score;
			result = max(result, solution(idx + 1, tempHorses));
			isHorse[next] = false;
			isHorse[present] = true;
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 10; i++)
	{
		int temp;
		cin >> temp;
		dice.push_back(temp);
	}

	init();

	vector<horse> horses;
	for (int i = 0; i < 4; i++)
	{
		horse temp = { START, 0 };
		horses.push_back(temp);
	}

	int answer = solution(0, horses);

	cout << answer << '\n';

	return 0;
}