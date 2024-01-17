#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

/*
    x^2 + y^2 = r2^2
    y^2 = r2^2 - x^2
    y = (r2^2 - x^2)^(1/2)
*/

ll calculateHigh(ll x, ll r) {
    ll lx = (ll)x;
    ll lr = (ll)r;
    
    ll ySquare = (r * r - x * x);
    double yRoot = sqrt(ySquare);
    return (ll)yRoot;
}

ll calculateLow(ll x, ll r) {
    ll lx = (ll)x;
    ll lr = (ll)r;
    
    ll ySquare = (r * r - x * x);
    
    double yRoot = sqrt(ySquare);
    return (ll)ceil(yRoot);
}

long long solution(int r1, int r2) {
    long long answer = 0;
    
    // 축 위의 점들 구하기
    answer += (r2 - r1 + 1) * 4;
    
    ll temp = 0;
    for (int x = 1; x <= r1 - 1; x++) {
        ll higher = calculateHigh(x, r2);
        ll lower = calculateLow(x, r1);
        
        temp += (higher - lower + 1);
    }
    answer += temp * 4;
    
    ll higher = calculateHigh(r1, r2);
    ll lower = 1;
    
    answer += (higher - lower + 1) * 4;
    
    temp = 0;
    for (int x = r1 + 1; x <= r2 - 1; x++) {
        ll higher = calculateHigh(x, r2);
        ll lower = 1;
        
        temp += (higher - lower + 1);
    }
    answer += temp * 4;
    
    return answer;
}