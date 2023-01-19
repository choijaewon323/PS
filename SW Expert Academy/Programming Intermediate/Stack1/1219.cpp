#include <iostream>
#include <vector>

using namespace std;

bool isVisited[100];

void dfs(vector<int> adjacent[100], int start)
{
	isVisited[start] = true;

	for (auto i : adjacent[start])
	{
		if (!isVisited[i])
		{
			dfs(adjacent, i);
		}
	}
}

int main(int argc, char **argv)
{
	int test_case;
	int testNum;
	int result;

	for (test_case = 1; test_case <= 10; test_case++)
	{
		int wholeCount;
		vector<int> adjacent[100];
		cin >> testNum >> wholeCount;

		for (int i = 0; i < 100; i++)
		{
			isVisited[i] = false;
 		}

		for (int i = 0; i < wholeCount; i++)
		{
			int a, b;
			cin >> a >> b;
			adjacent[a].push_back(b);
		}

		dfs(adjacent, 0);

		if (isVisited[99])
		{
			result = 1;
		}
		else
		{
			result = 0;
		}

		cout << "#" << test_case << " " << result << '\n';
	}
}