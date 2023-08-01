#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define UP 0
#define UPLEFT 1
#define LEFT 2
#define DOWNLEFT 3
#define DOWN 4
#define DOWNRIGHT 5
#define RIGHT 6
#define UPRIGHT 7

#define SHARK -1
#define FISH -2
#define EMPTY 0

struct node
{
	int type;
	int num;
	int direction;
};

pair<int, int> nextPos(int direction, int cnt, int y, int x)
{
	for (int i = 0; i < cnt; i++)
	{
		switch (direction)
		{
		case UP:
			y--;
			break;

		case UPLEFT:
			y--;
			x--;
			break;

		case LEFT:
			x--;
			break;

		case DOWNLEFT:
			y++;
			x--;
			break;

		case DOWN:
			y++;
			break;

		case DOWNRIGHT:
			y++;
			x++;
			break;

		case RIGHT:
			x++;
			break;

		case UPRIGHT:
			y--;
			x++;
			break;
		}
	}
	
	return { y, x };
}

bool inRange(int y, int x)
{
	if (0 <= y && y < 4 && 0 <= x && x < 4)
	{
		return true;
	}
	return false;
}

void swap(node &a, node &b)
{
	node temp = a;
	a = b;
	b = temp;
}

void fishMove(vector<vector<node>> &nodes, int fishNum)
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (nodes[y][x].type == FISH && nodes[y][x].num == fishNum)
			{
				int direction = nodes[y][x].direction;

				for (int i = 0; i < 8; i++)
				{
					int tempDirect = direction + i;
					tempDirect %= 8;

					nodes[y][x].direction = tempDirect;
					pair<int, int> next = nextPos(tempDirect, 1, y, x);
					if (inRange(next.first, next.second))
					{
						node &temp = nodes[next.first][next.second];

						if (temp.type == EMPTY || temp.type == FISH)
						{
							swap(nodes[y][x], temp);

							return;
						}
					}
				}

				return;
			}
		}
	}
}

void print(vector<vector<node>> nodes)
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			cout << nodes[y][x].num << " ";
		}
		cout << '\n';
	}
}

pair<int, int> findShark(vector<vector<node>> &nodes)
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (nodes[y][x].type == SHARK)
			{
				return { y, x };
			}
		}
	}
	return { -1, -1 };
}

pair<int, int> sharkMove(vector<vector<node>> &nodes, int cnt, pair<int, int> shark)
{
	node temp = nodes[shark.first][shark.second];
	int direction = temp.direction;

	pair<int, int> next = nextPos(direction, cnt, shark.first, shark.second);

	if (inRange(next.first, next.second))
	{
		if (nodes[next.first][next.second].type == FISH)
		{
			return { next.first, next.second };
		}
		else
		{
			return { -1, -1 };
		}
	}
	else
	{
		return { -1, -1 };
	}
}

int solution(vector<vector<node>> nodes)
{
	// fish move
	for (int i = 1; i <= 16; i++)
	{
		fishMove(nodes, i);
	}

	// shark move
	int result = 0;
	pair<int, int> shark = findShark(nodes);
	for (int i = 1; i <= 3; i++)
	{
		pair<int, int> next = sharkMove(nodes, i, shark);

		if (next.first != -1 && next.second != -1)
		{
			vector<vector<node>> tempNodes = nodes;

			int num = tempNodes[next.first][next.second].num;
			int direction = tempNodes[next.first][next.second].direction;

			tempNodes[next.first][next.second] = { SHARK, num, direction };
			tempNodes[shark.first][shark.second] = { EMPTY, 0, 0 };

			result = max(result, solution(tempNodes) + num);
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<vector<node>> nodes(4, vector<node>(4));

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			int a, b;
			cin >> a >> b;
			nodes[y][x] = { FISH, a, b - 1 };
		}
	}

	// 0,0 shark
	int answer = nodes[0][0].num;
	nodes[0][0] = { SHARK, -1, nodes[0][0].direction };

	answer += solution(nodes);

	cout << answer << '\n';

	return 0;
}