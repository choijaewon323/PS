#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int map[27][27];
vector<pair<int, int>> houseLocation;
bool isChecked[27][27];
vector<int> numOfInsideComplex;
int numOfComplex;
void bfs(int n1, int n2)
{
	isChecked[n1][n2] = true;
	queue<pair<int, int>> q;
	int num = 0;
	q.push(make_pair(n1, n2));
	while (true)
	{
		pair<int, int> node = q.front();
		int y, x;
		isChecked[node.first][node.second] = true;
		num++;
		y = node.first + 1;
		x = node.second;
		if (!isChecked[y][x])
		{
			if (map[y][x])
			{
				isChecked[y][x] = true;
				q.push(make_pair(y, x));
			}
		}
		y = node.first;
		x = node.second + 1;
		if (!isChecked[y][x])
		{
			if (map[y][x])
			{
				isChecked[y][x] = true;
				q.push(make_pair(y, x));
			}
		}
		y = node.first - 1;
		x = node.second;
		if (!isChecked[y][x])
		{
			if (map[y][x])
			{
				isChecked[y][x] = true;
				q.push(make_pair(y, x));
			}
		}
		y = node.first;
		x = node.second - 1;
		if (!isChecked[y][x])
		{
			if (map[y][x])
			{
				isChecked[y][x] = true;
				q.push(make_pair(y, x));
			}
		}
		q.pop();
		if (q.empty())
		{
			break;
		}
	}
	numOfInsideComplex.push_back(num);
	numOfComplex++;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string input;
		cin >> input;
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = input[j - 1] - '0';
			if (map[i][j] == 1)
			{
				houseLocation.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < houseLocation.size(); i++)
	{
		int n1 = houseLocation[i].first;
		int n2 = houseLocation[i].second;
		if (isChecked[n1][n2])
		{
			continue;
		}
		bfs(n1, n2);
	}
	sort(numOfInsideComplex.begin(), numOfInsideComplex.end());
	cout << numOfComplex << '\n';
	for (auto i : numOfInsideComplex)
	{
		cout << i << '\n';
	}
	return 0;
}