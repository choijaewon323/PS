#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int operD(int temp)
{
	temp *= 2;
	temp %= 10000;

	return temp;
}

int operS(int temp)
{
	
	if (temp == 0)
	{
		temp = 9999;
	}
	else
	{
		temp--;
	}

	return temp;
}

int operL(int temp)
{
	int result = (temp % 1000 * 10) + temp / 1000;

	return result;
}

int operR(int temp)
{
	int result = (temp / 10) + temp % 10 * 1000;

	return result;
}

vector<string> visited;
vector<bool> visited2;

string bfs(int a, int b)
{
	queue<int> q;

	visited[a] = "";
	visited2[a] = true;
	q.push(a);

	while (!q.empty())
	{
		int present = q.front();
		int next;
		q.pop();

		if (present == b)
		{
			return visited[present];
		}

		next = operD(present);
		if (!visited2[next])
		{
			visited2[next] = true;
			visited[next] = visited[present] + "D";
			q.push(next);
		}

		next = operS(present);
		if (!visited2[next])
		{
			visited2[next] = true;
			visited[next] = visited[present] + "S";
			q.push(next);
		}

		next = operL(present);
		if (!visited2[next])
		{
			visited2[next] = true;
			visited[next] = visited[present] + "L";
			q.push(next);
		}

		next = operR(present);
		if (!visited2[next])
		{
			visited2[next] = true;
			visited[next] = visited[present] + "R";
			q.push(next);
		}
	}

	return "";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int test_case;

	cin >> test_case;

	for (int test = 0; test < test_case; test++)
	{
		int a, b;
		string answer;

		cin >> a >> b;

		visited = vector<string>(10000, "");
		visited2 = vector<bool>(10000, false);

		answer = bfs(a, b);

		cout << answer << '\n';
	}
	
	return 0;
}