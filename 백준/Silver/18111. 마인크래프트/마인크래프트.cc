#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

#define MAX 500
#define INF 1000000000

int N, M, B;
int matrix[MAX][MAX];

void input()
{
	cin >> N >> M >> B;
	
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> matrix[y][x];
		}
	}
}

int makeFlat(const int height)
{
	int more = 0;
	int less = 0;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (matrix[y][x] > height)
			{
				const int dist = matrix[y][x] - height;
				
				more += dist;
			}
			else if (matrix[y][x] < height)
			{
				const int dist = height - matrix[y][x];

				less += dist;
			}
			else
			{
				continue;
			}
		}
	}

	const int allBlocks = B + more;

	if (allBlocks < less)
	{
		return -1;
	}

	const int result = 2 * more + less;

	return result;
}

pair<int, int> solve()
{
	pair<int, int> answer = { INF, -1 };
	
	for (int height = 0; height <= 256; height++)
	{
		const int temp = makeFlat(height);

		if (temp == -1)
		{
			continue;
		}

		if (temp <= answer.first)
		{
			answer.first = temp;
			answer.second = height;
		}
	}

	return answer;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	const pair<int, int> answer = solve();

	cout << answer.first << " " << answer.second << '\n';

	return 0;
}