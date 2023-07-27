#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int H, W, N, M;
	int height = 0, width = 0;

	cin >> H >> W >> N >> M;

	for (int y = 0; y < H; y += (N + 1))
	{
		height++;
	}

	for (int x = 0; x < W; x += (M + 1))
	{
		width++;
	}

	cout << height * width << '\n';

	return 0;
}