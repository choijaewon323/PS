/*
	사대의 수 M [1, 100,000]
	동물의 수 N [1, 100,000]
	사정거리 L [1, 1,000,000,000]

	각 사대에 대해서 동물을 루프 돌려서 사정거리 안인지 찾기
	O(MN) -> 100,000 x 100,000 -> 시간 초과

	O(N log N) 알고리즘이 필요하다.

	각 사대나 동물에 대해 이분 탐색으로 반대의 물체들을 찾을 수 있어야 한다.


	이분 탐색을 쓴다 -> 말도 안되는 범위의 입력 값에 적용한다.
	파라매틱 서치

	사정거리에 이분 탐색을 갈겨야함 -> 이게 말이 되나?

	이분 탐색이 가능하다 -> 정렬이 되어있어야 한다.

	사대가 y좌표 고정이므로 사대를 기준으로 오름차순 정렬
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int M, N, L;

vector<int> shoots;
vector<pair<int, int>> animals;

int absolute(int num) {
	if (num < 0) {
		return -num;
	}
	return num;
}

bool binarySearch(int animalX, int animalY) {
	int left = 0;
	int right = shoots.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (absolute(shoots[mid] - animalX) + animalY <= L) {
			return true;
		}
		else {
			if (shoots[mid] > animalX) {
				right = mid - 1;
			}
			else if (shoots[mid] < animalX) {
				left = mid + 1;
			}
			else {
				return false;
			}
		}
	}

	return false;
}

int main() {
	cin >> M >> N >> L;

	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		shoots.push_back(temp);
	}

	sort(shoots.begin(), shoots.end());

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		animals.push_back({ x, y });
	}

	int answer = 0;
	for (pair<int, int> &animal : animals) {
		int x = animal.first;
		int y = animal.second;

		if (binarySearch(x, y)) {
			answer++;
		}
	}

	cout << answer << '\n';

	return 0;
}