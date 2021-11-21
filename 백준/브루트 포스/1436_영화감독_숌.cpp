#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	int countOfNum = 0;
	int count = 0;
	cin >> n;

	while (countOfNum != n)
	{
		string temp = to_string(count);
		if (temp.find("666") != string::npos)
		{
			countOfNum++;
		}

		count++;
	}

	cout << count - 1 << '\n';

	return 0;
}