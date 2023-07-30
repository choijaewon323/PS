#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<int> &note1, int num)
{
	int left = 0;
	int right = note1.size() - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (note1[mid] == num)
		{
			return 1;
		}
		else if (note1[mid] > num)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return 0;
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
		vector<int> note1;
		vector<int> answer;
		int N, temp;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> temp;
			note1.push_back(temp);
		}
		sort(note1.begin(), note1.end());
		int M;
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> temp;
			int result = binary_search(note1, temp);
			answer.push_back(result);
		}
		for (int a : answer)
		{
			cout << a << '\n';
		}
	}

	return 0;
}