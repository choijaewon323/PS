#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 20

int n;
int answer = -1;

vector<vector<int>> up(vector<vector<int>>& board)
{
	vector<vector<int>> result(n, vector<int>(n, 0));

	for (int x = 0; x < n; x++)
	{
		queue<int> q;
		for (int y = 0; y < n; y++)
		{
			if (board[y][x] > 0)
			{
				q.push(board[y][x]);
			}
		}
		
		vector<int> temp;
		while (!q.empty())
		{
			int present = q.front();
			q.pop();

			if (!q.empty())
			{
				int pre = q.front();

				if (pre == present)
				{
					q.pop();
					present += pre;
				}
			}

			temp.push_back(present);
		}

		int i = 0;
		for (int y = 0; y < n; y++)
		{
			if (i < temp.size())
			{
				result[y][x] = temp[i++];
				continue;
			}
			result[y][x] = 0;
		}
	}

	return result;
}

vector<vector<int>> down(vector<vector<int>>& board)
{
	vector<vector<int>> result(n, vector<int>(n, 0));

	for (int x = 0; x < n; x++)
	{
		queue<int> q;
		for (int y = n - 1; y >= 0; y--)
		{
			if (board[y][x] > 0)
			{
				q.push(board[y][x]);
			}
		}

		vector<int> temp;
		while (!q.empty())
		{
			int present = q.front();
			q.pop();

			if (!q.empty())
			{
				int pre = q.front();

				if (pre == present)
				{
					q.pop();
					present += pre;
				}
			}

			temp.push_back(present);
		}

		int i = 0;
		for (int y = n - 1; y >= 0; y--)
		{
			if (i < temp.size())
			{
				result[y][x] = temp[i++];
				continue;
			}
			result[y][x] = 0;
		}
	}

	return result;
}

vector<vector<int>> left(vector<vector<int>>& board)
{
	vector<vector<int>> result(n, vector<int>(n, 0));

	for (int y = 0; y < n; y++)
	{
		queue<int> q;
		for (int x = 0; x < n; x++)
		{
			if (board[y][x] > 0)
			{
				q.push(board[y][x]);
			}
		}

		vector<int> temp;
		while (!q.empty())
		{
			int present = q.front();
			q.pop();

			if (!q.empty())
			{
				int pre = q.front();

				if (pre == present)
				{
					q.pop();
					present += pre;
				}
			}

			temp.push_back(present);
		}

		int i = 0;
		for (int x = 0; x < n; x++)
		{
			if (i < temp.size())
			{
				result[y][x] = temp[i++];
				continue;
			}
			result[y][x] = 0;
		}
	}

	return result;
}

vector<vector<int>> right(vector<vector<int>>& board)
{
	vector<vector<int>> result(n, vector<int>(n, 0));

	for (int y = 0; y < n; y++)
	{
		queue<int> q;
		for (int x = n - 1; x >= 0; x--)
		{
			if (board[y][x] > 0)
			{
				q.push(board[y][x]);
			}
		}

		vector<int> temp;
		while (!q.empty())
		{
			int present = q.front();
			q.pop();

			if (!q.empty())
			{
				int pre = q.front();

				if (pre == present)
				{
					q.pop();
					present += pre;
				}
			}

			temp.push_back(present);
		}

		int i = 0;
		for (int x = n - 1; x >= 0; x--)
		{
			if (i < temp.size())
			{
				result[y][x] = temp[i++];
				continue;
			}
			result[y][x] = 0;
		}
	}

	return result;
}

void func(vector<vector<int>>& board, int cnt)
{
	if (cnt == 5)
	{
		// check
		int res = -1;
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				res = max(res, board[y][x]);
			}
		}

		answer = max(answer, res);
		return;
	}
	vector<vector<int>> temp;

	temp = up(board);
	func(temp, cnt + 1);

	temp = down(board);
	func(temp, cnt + 1);

	temp = left(board);
	func(temp, cnt + 1);

	temp = right(board);
	func(temp, cnt + 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	vector<vector<int>> board(n, vector<int>(n, 0));

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> board[y][x];
		}
	}

	func(board, 0);

	cout << answer << '\n';

	return 0;
}