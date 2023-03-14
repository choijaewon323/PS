#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef struct _node
{
	string name;
	int kor;
	int eng;
	int math;
} node;

bool compare(node &a, node &b)
{
	if (a.kor == b.kor && a.eng == b.eng && a.math == b.math)
	{
		return a.name < b.name;
	}
	if (a.kor == b.kor && a.eng == b.eng)
	{
		return a.math > b.math;
	}
	if (a.kor == b.kor)
	{
		return a.eng < b.eng;
	}
	return a.kor > b.kor;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<node> nodes;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		node temp;

		cin >> temp.name >> temp.kor >> temp.eng >> temp.math;

		nodes.push_back(temp);
	}

	sort(nodes.begin(), nodes.end(), compare);

	for (auto nod : nodes)
	{
		cout << nod.name << '\n';
	}

	return 0;
}