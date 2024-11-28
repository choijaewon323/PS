#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	절댓값이 가장 작은 두 용액을 넣는다.

	N <= 100,000 -> O(N log N) 가능

	수는 모두 -10억에서 10억 사이(닫힌 구간)
	
	투 포인터를 사용한다면? O(N) 시간에 가능

	left, right 정의

	양 끝단에서 시작
	- 서로 만나는 순간 끝남
	
	둘이 서로 왼쪽 or 오른쪽을 비교
		더 값이 작아지는 쪽으로 간다.
		
*/

vector<int> input;
int N;

int absolute(int n) {
	return n >= 0 ? n : -n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		input.push_back(tmp);
	}

	sort(input.begin(), input.end());

	int left = 0;
	int right = input.size() - 1;
	int answer = absolute(input[left] + input[right]);
	pair<int, int> result = { input[left], input[right] };
	
	while (left < right) {
		int presentSum = absolute(input[left] + input[right]);
		
		if (presentSum < answer) {
			answer = presentSum;
			result = { input[left], input[right] };
		}

		int nextLeft = input[left + 1];
		int nextRight = input[right - 1];
		
		if (absolute(nextLeft + input[right]) >= absolute(input[left] + nextRight)) {
			right--;
		} else {
			left++;
		}
	}

	cout << result.first << " " << result.second << '\n';

	return 0;
}