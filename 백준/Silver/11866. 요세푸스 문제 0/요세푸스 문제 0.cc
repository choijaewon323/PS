#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <utility>

using namespace std;

queue<int> makeQueue(const int N)
{
	queue<int> result;
	for (int i = 1; i <= N; i++)
	{
		result.push(i);
	}

	return result;
}

void roll(queue<int> &q, const int K)
{
	for (int i = 0; i < K - 1; i++)
	{
		const int fr = q.front();
		q.pop();
		q.push(fr);
	}
}

vector<int> solve(const int N, const int K)
{
	queue<int> q = makeQueue(N);
	
	vector<int> results;
	while (!q.empty())
	{
		roll(q, K);

		results.push_back(q.front());
		q.pop();
	}

	return results;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	vector<int> answers = solve(N, K);

	cout << "<";
	for (int i = 0; i < answers.size() - 1; i++)
	{
		const int temp = answers[i];
		cout << temp << ", ";
	}
	cout << answers.back() << ">" << '\n';

	return 0;
}