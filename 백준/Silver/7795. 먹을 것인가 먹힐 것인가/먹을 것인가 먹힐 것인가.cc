#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lowerBound(vector<int> &A, int num)
{
	int left = 0;
	int right = A.size() - 1;
	int answer = -1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (A[mid] > num)
		{
			answer = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		vector<int> A;
		vector<int> B;
		int N, M, temp;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			cin >> temp;
			A.push_back(temp);
		}
		sort(A.begin(), A.end());
		for (int i = 0; i < M; i++)
		{
			cin >> temp;
			B.push_back(temp);
		}
		sort(B.begin(), B.end());

		int answer = 0;
		for (int b : B)
		{
			int index = lowerBound(A, b);
			if (index == -1)
			{
				continue;
			}
			answer += A.size() - index;
		}

		cout << answer << '\n';
	}

	return 0;
}