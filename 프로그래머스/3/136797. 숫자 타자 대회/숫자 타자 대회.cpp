#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

map<int, pair<int, int>> numberToCoor;
map<pair<int, int>, int> coorToNumber;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int dy2[] = {-1, -1, 1, 1};
int dx2[] = {-1, 1, -1, 1};
int dp[10][10][100000];

void init() {
    numberToCoor[1] = {0, 0};
    numberToCoor[2] = {0, 1};
    numberToCoor[3] = {0, 2};
    numberToCoor[4] = {1, 0};
    numberToCoor[5] = {1, 1};
    numberToCoor[6] = {1, 2};
    numberToCoor[7] = {2, 0};
    numberToCoor[8] = {2, 1};
    numberToCoor[9] = {2, 2};
    numberToCoor[0] = {3, 1};
    coorToNumber[{0, 0}] = 1;
    coorToNumber[{0, 1}] = 2;
    coorToNumber[{0, 2}] = 3;
    coorToNumber[{1, 0}] = 4;
    coorToNumber[{1, 1}] = 5;
    coorToNumber[{1, 2}] = 6;
    coorToNumber[{2, 0}] = 7;
    coorToNumber[{2, 1}] = 8;
    coorToNumber[{2, 2}] = 9;
    coorToNumber[{3, 1}] = 0;
}

bool isSame(pair<int, int>& src, pair<int, int>& dst) {
    return (src == dst);
}

bool isOrthogonal(pair<int, int>& src, pair<int, int>& dst) {
    int y = src.first;
    int x = src.second;
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (dst.first == ny && dst.second == nx) {
            return true;
        }
    }
    return false;
}

bool isDiagonal(pair<int, int>& src, pair<int, int>& dst) {
    int y = src.first;
    int x = src.second;
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy2[i];
        int nx = x + dx2[i];
        
        if (dst.first == ny && dst.second == nx) {
            return true;
        }
    }
    return false;
}

pair<int, int> findNext(pair<int, int>& src, pair<int, int>& dst) {
    pair<int, int> nextCoor = src;
    
    int sy = src.first;
    int sx = src.second;
    int ny = dst.first;
    int nx = dst.second;
    int cost = 0;
    
    int distY = sy - ny;
    int distX = sx - nx;
    
    if (distY > 0) {    // src가 더 아래에
        if (distX > 0) {    // src가 오른쪽에
            nextCoor.first--;
            nextCoor.second--;
            cost = 3;
        } else if (distX < 0) { // src가 왼쪽에
            nextCoor.first--;
            nextCoor.second++;
            cost = 3;
        } else {    // 같음
            nextCoor.first--;
            cost = 2;
        }
    } else if (distY < 0) {     // src가 더 위에
        if (distX > 0) {    // src가 오른쪽에
            nextCoor.first++;
            nextCoor.second--;
            cost = 3;
        } else if (distX < 0) { // src가 왼쪽에
            nextCoor.first++;
            nextCoor.second++;
            cost = 3;
        } else {    // 같음
            nextCoor.first++;
            cost = 2;
        }
    } else {    // src와 dst가 같은 높이에
        if (distX > 0) {    // src가 오른쪽에
            nextCoor.second--;
            cost = 2;
        } else if (distX < 0) { // src가 왼쪽에
            nextCoor.second++;
            cost = 2;
        } else {    // 일치 (불가능)
            
        }
    }
    
    int number = coorToNumber[nextCoor];
    return {number, cost};
}

int calculate(int src, int dst) {
    pair<int, int>& srcCoor = numberToCoor[src];
    pair<int, int>& dstCoor = numberToCoor[dst];
    
    if (isSame(srcCoor, dstCoor)) {
        return 1;
    }
    if (isOrthogonal(srcCoor, dstCoor)) {
        return 2;
    }
    if (isDiagonal(srcCoor, dstCoor)) {
        return 3;
    }
    
    pair<int, int> nextInfo = findNext(srcCoor, dstCoor);
    int nextNumber = nextInfo.first;
    int cost = nextInfo.second;
    
    return calculate(nextNumber, dst) + cost;
}

int solve(int left, int right, int index, string& numbers) {
    // base case
    if (index == numbers.size()) {
        return 0;
    }
    if (dp[left][right][index] != 0) {
        return dp[left][right][index];
    }
    
    int presentNumber = numbers[index] - '0';
    
    // calculate cost
    int leftCost = calculate(left, presentNumber);
    int rightCost = calculate(right, presentNumber);
    
    // 둘 중 하나라도 가중치가 1이면(제자리면) 무조건 걔를 눌러야함
    if (leftCost == 1) {
        return dp[left][right][index] = solve(presentNumber, right, index + 1, numbers) + leftCost;
    } else if (rightCost == 1) {
        return dp[left][right][index] = solve(left, presentNumber, index + 1, numbers) + rightCost;
    } else {    // 그게 아니라면, 둘다 실행해봐야함
        int leftMove = solve(presentNumber, right, index + 1, numbers) + leftCost;
        int rightMove = solve(left, presentNumber, index + 1, numbers) + rightCost;
        
        return dp[left][right][index] = min(leftMove, rightMove);
    }
}

int solution(string numbers) {
    init();
    int answer = solve(4, 6, 0, numbers);
    
    return answer;
}