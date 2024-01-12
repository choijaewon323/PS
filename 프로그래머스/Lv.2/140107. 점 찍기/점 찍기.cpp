#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

double boundY(int x, int d) {
    ll squareX = (ll)x * (ll)x;
    ll squareD = (ll)d * (ll)d;
    
    ll squareY = squareD - squareX;
    
    return sqrt(squareY);
}

long long solution(int k, int d) {
    long long answer = 0;
    
    // (0, 0) 계산
    answer++;
    
    // 축 포함 점 미리 계산
    answer += (d / k) * 2;
    
    ll temp = 0;
    for (int i = k; i < d; i += k) {
        double dy = boundY(i, d);
        ll maxY = (ll)dy;
        temp += maxY / k;
    }
    
    answer += temp;
    
    return answer;
}