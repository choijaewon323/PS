#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
double maxValue;
vector<double> scores;

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		double temp;
		cin >> temp;

		scores.push_back(temp);
		maxValue = max(maxValue, temp);
	}
}

void solve()
{
	double acc = 0;
	for (double &score : scores)
	{
		score = score / maxValue * 100;
		acc += score;
	}

	cout << acc / scores.size() << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	
	solve();

	return 0;
}