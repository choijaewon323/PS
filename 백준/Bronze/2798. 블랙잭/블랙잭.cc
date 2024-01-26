#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 100

int N, M;
int cards[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		cards[i] = temp;
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				const int tempSum = cards[i] + cards[j] + cards[k];

				if (tempSum <= M)
				{
					answer = max(answer, tempSum);
				}
			}
		}
	}

	cout << answer << '\n';
	
	return 0;
}