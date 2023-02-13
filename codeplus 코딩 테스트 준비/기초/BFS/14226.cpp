#include <iostream>
#include <queue>
using namespace std;

typedef struct _node
{
	int screen;
	int clipboard;
	int second;
} node;

int s;
bool visited[10001][10001];

int bfs()
{
	queue<node> q;
	node start = { 1, 0, 0 };
	q.push(start);

	while (!q.empty())
	{
		node present = q.front();
		q.pop();
		int tempScreen = present.screen;
		int tempClipboard = present.clipboard;
		int tempSecond = present.second;

		if (tempScreen == s)
		{
			return tempSecond;
		}

		// 1
		if (tempScreen > 0)
		{
			if (!visited[tempScreen][tempScreen])
			{
				visited[tempScreen][tempScreen] = true;
				node newNode = { tempScreen, tempScreen, tempSecond + 1 };
				q.push(newNode);
			}
		}

		// 2
		if (tempClipboard > 0)
		{
			if (!visited[tempScreen + tempClipboard][tempClipboard])
			{
				visited[tempScreen + tempClipboard][tempClipboard] = true;
				node newNode = { tempScreen + tempClipboard, tempClipboard, tempSecond + 1 };
				q.push(newNode);
			}
		}

		// 3
		if (tempScreen > 0)
		{
			if (!visited[tempScreen - 1][tempClipboard])
			{
				visited[tempScreen - 1][tempClipboard] = true;
				node newNode = { tempScreen - 1, tempClipboard, tempSecond + 1 };
				q.push(newNode);
			}
		}
	}

	return 0;
}

int main()
{
	cin >> s;

	cout << bfs() << '\n';

	return 0;
}