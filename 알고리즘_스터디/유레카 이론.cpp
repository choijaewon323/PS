#include <iostream>
#include <vector>
using namespace std;

vector<int> triangleNum;

int main()
{
	int num = (1 * 2) / 2;
	int k, number;

	triangleNum.push_back(num);

	for(int i = 2; num <= 1000; i++)
	{
		num = (i * (i + 1)) / 2;
		triangleNum.push_back(num);
	}

	cin >> k;

	bool flag = false;

	for(int i = 0; i < k; i++)
	{
		cin >> number;
		for(auto element1 : triangleNum)
		{
			for(auto element2 : triangleNum)
			{
				for(auto element3 : triangleNum)
				{
					if(number == element1 + element2 + element3)
					{
						flag = true;
					}
				}
			}
		}
		cout << flag << '\n';
		flag = false;
	}
	return 0;
}