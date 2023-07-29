#include <iostream>

using namespace std;

bool matrix[500][500];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int H, W;

	cin >> H >> W;

	for (int width = 0; width < W; width++)
	{
		int height;

		cin >> height;

		for (int y = 0; y < height; y++)
		{
			matrix[y][width] = true;
		}
	}

	int answer = 0;
	for (int y = 0; y < H; y++)
	{
		bool isLocked = false;
		int cnt = 0;
		for (int x = 0; x < W; x++)
		{
			if (!isLocked && matrix[y][x] == true)
			{
				isLocked = true;
			}
			else if (isLocked)
			{
				if (matrix[y][x] == false)	// water
				{
					cnt++;
				}
				else	// block
				{
					answer += cnt;
					cnt = 0;
				}
			}
		}
	}

	cout << answer << '\n';

	return 0;
}