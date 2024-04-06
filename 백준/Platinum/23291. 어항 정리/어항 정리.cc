#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

/*
	상어가 가지고 있는 어항 N개

	어항에는 물고기 한마리 이상 있음

	1. 물고기 수가 가장 적은 어항에 물고기 한마리 넣음
		여러개라면 모두에 한마리씩 넣음

	2. 공중부양 어쩌고
	2-1 bfs 실행 -> 동시이므로 벡터 변경
	2-2 바닥에 다시 놓음

	3. 공중부양2 -> 가운데로
*/

int N, K;
vector<deque<int>> bowl;

void input() {
	cin >> N >> K;
	bowl = vector<deque<int>>(N);

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		bowl[i].push_back(temp);
	}
}

int findMin() {
	int minResult = 100000000;

	for (int i = 0; i < N; i++) {
		int temp = bowl[i].front();

		minResult = min(minResult, temp);
	}

	return minResult;
}

void addFish() {
	int minValue = findMin();

	for (int i = 0; i < N; i++) {
		int& temp = bowl[i].front();
		
		if (temp == minValue) {
			temp++;
		}
	}
}

pair<int, int> findStartEnd() {
	vector<int> temp;

	for (int i = 0; i < N; i++) {
		if (bowl[i].empty()) {
			continue;
		}

		if (bowl[i].size() >= 2) {
			temp.push_back(i);
		} else if (bowl[i].size() == 1) {
			break;
		}
	}

	pair<int, int> result = { temp.front(), temp.back() };
	return result;
}

bool canStack(int endIndex) {
	int dest = N - 1;
	int rest = dest - endIndex;
	
	if (bowl[endIndex].size() <= rest) {
		return true;
	}
	return false;
}

void stack(int startIndex, int endIndex) {
	int height = bowl[startIndex].size();

	for (int i = endIndex; i >= startIndex; i--) {
		for (int j = endIndex + 1; j < endIndex + 1 + height; j++) {
			int temp = bowl[i].front();
			bowl[i].pop_front();

			bowl[j].push_back(temp);
		}
	}
}

void firstFunc() {
	// first place
	int first = bowl[0].front();
	bowl[0].pop_front();
	bowl[1].push_back(first);

	while (true) {
		pair<int, int> startEnd = findStartEnd();
		int startIndex = startEnd.first;
		int endIndex = startEnd.second;

		if (canStack(endIndex)) {
			stack(startIndex, endIndex);
		} else {
			break;
		}
	}
}

vector<vector<int>> makeInitMap() {
	vector<vector<int>> result(50, vector<int>(N, -1));

	for (int x = 0; x < N; x++) {
		if (!bowl[x].empty()) {
			int size = bowl[x].size();
			int bottomY = 50 - 1;

			for (int y = bottomY; y >= bottomY - size + 1; y--) {
				int fr = bowl[x].front();
				bowl[x].pop_front();
				result[y][x] = fr;
			}
		}
	}

	return result;
}

pair<int, int> findStartPoint(vector<vector<int>>& init) {
	for (int y = 50 - 1; y >= 0; y--) {
		for (int x = 0; x < N; x++) {
			if (init[y][x] != -1) {
				return { y, x };
			}
		}
	}
	return { -1, -1 };
}

int dy[] = { 1, 0 };
int dx[] = { 0, 1 };

bool inRange(int y, int x) {
	if (0 <= y && y < 50 && 0 <= x && x < N) {
		return true;
	}
	return false;
}

bool isNotMinus(int y, int x, vector<vector<int>>& mp) {
	if (mp[y][x] != -1) {
		return true;
	}

	return false;
}

int absolute(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

void printMap(vector<vector<int>> &);

vector<vector<int>> bfs() {
	vector<vector<int>> initMap = makeInitMap();
	vector<vector<int>> result = initMap;
	//printMap(initMap);
	vector<vector<bool>> visited(50, vector<bool>(N, false));

	for (int y = 0; y < 50; y++) {
		for (int x = 0; x < N; x++) {
			if (initMap[y][x] == -1) {
				continue;
			}

			for (int i = 0; i < 2; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (inRange(ny, nx) && isNotMinus(ny, nx, initMap)) {
					int dist = initMap[y][x] - initMap[ny][nx];
					int absDist = absolute(dist);
					absDist /= 5;

					if (absDist > 0) {
						if (dist > 0) {
							result[ny][nx] += absDist;
							result[y][x] -= absDist;
						} else {
							result[y][x] += absDist;
							result[ny][nx] -= absDist;
						}
					}
				}
			}
		}
	}

	/*
	pair<int, int> startPoint = findStartPoint(initMap);
	queue<pair<int, int>> q;
	
	visited[startPoint.first][startPoint.second] = true;
	q.push(startPoint);

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (inRange(ny, nx) && isNotMinus(ny, nx, initMap) && !visited[ny][nx]) {
				visited[ny][nx] = true;
				q.push({ ny, nx });
				int dist = initMap[y][x] - initMap[ny][nx];
				int absDist = absolute(dist);
				absDist /= 5;

				if (absDist > 0) {
					if (dist > 0) {
						result[ny][nx] += absDist;
						result[y][x] -= absDist;
					} else {
						result[y][x] += absDist;
						result[ny][nx] -= absDist;
					}
				}
			}
		}
	}
	*/
	

	return result;
}

void mapToDeq(vector<vector<int>> &mp) {
	int bottomY = 50 - 1;
	int start = 0;

	for (int x = 0; x < N; x++) {
		for (int y = bottomY; y >= 0; y--) {
			int temp = mp[y][x];
			
			if (temp == -1) {
				break;
			}

			bowl[start].push_back(temp);
			start++;
		}
	}
}

void print() {
	for (int i = 0; i < N; i++) {
		cout << bowl[i].front() << " ";
	}
	cout << '\n';
}

void printStack() {
	for (int i = 0; i < N; i++) {
		cout << bowl[i].size() << " ";
	}
	cout << '\n';
}

void printMap(vector<vector<int>> &mp) {
	int height = mp.size();
	int width = mp[0].size();
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cout << mp[y][x] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void secondFunc() {
	int right = N - 1;
	for (int x = 0; x < N / 2; x++) {
		int temp = bowl[x].back();
		bowl[x].pop_back();

		bowl[right].push_back(temp);
		right--;
	}

	right = N - 1;
	for (int x = N / 2; x < N / 2 + N / 4; x++) {
		while (!bowl[x].empty()) {
			int temp = bowl[x].back();
			bowl[x].pop_back();

			bowl[right].push_back(temp);
		}
		right--;
	}
}

void solve() {
	addFish();
	//print();

	firstFunc();
	//printStack();
	vector<vector<int>> bfsRes = bfs();
	//printMap(bfsRes);
	mapToDeq(bfsRes);
	//print();

	secondFunc();
	//printStack();
	vector<vector<int>> bfsRes2 = bfs();
	//printMap(bfsRes2);
	mapToDeq(bfsRes2);
	//print();
}

int calculateDist() {
	int minVal = 100000000;
	int maxVal = -1;

	for (int i = 0; i < N; i++) {
		int temp = bowl[i].front();

		minVal = min(minVal, temp);
		maxVal = max(maxVal, temp);
	}

	return maxVal - minVal;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	int answer = 0;
	while (true) {
		answer++;
		solve();
		int dist = calculateDist();

		if (dist <= K) {
			cout << answer << '\n';
			return 0;
		}
	}

	return 0;
}