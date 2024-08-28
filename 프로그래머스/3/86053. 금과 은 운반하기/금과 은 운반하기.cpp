#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*

    1,000,000,000
    100,000 -> O(n log n) 까지만 가능
    
    이분탐색 -> 예상은 했지만 진짜 그런줄은...
    시간을 특정하고 그 시간 안에 금과 은을 옮길 수 있는가?
    광물의 최대 수보다도 더 많이 캔 다음에 원래 g, s 값과 min 하면 된다.
*/

typedef long long ll;

int A, B;
vector<int> gold;
vector<int> silver;
vector<int> weight;
vector<int> T;

bool isPossible(ll mid) {
    ll totalGold = 0;
    ll totalSilver = 0;
    ll totalWeight = 0;
    
    for (int i = 0; i < gold.size(); i++) {
        ll presentTime = T[i];
        
        ll aroundTime = presentTime * 2;
        ll maxCount = mid / aroundTime;
        
        if (mid % aroundTime >= presentTime) {
            maxCount++;
        }
        ll presentWeight = weight[i] * maxCount;
        
        totalGold += min((ll)gold[i], presentWeight);
        totalSilver += min((ll)silver[i], presentWeight);
        totalWeight += min((ll)(gold[i] + silver[i]), presentWeight);
    }
    
    if (totalGold >= A && totalSilver >= B && totalWeight >= A + B) {
        return true;
    }
    return false;
}

ll solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    A = a;
    B = b;
    gold = g;
    silver = s;
    weight = w;
    T = t;
    
    ll left = 0;
    ll right = 400000000000000;
    ll answer = right;
    while (left <= right) {
        ll mid = (left + right) / 2;
        
        if (isPossible(mid)) {
            answer = min(answer, mid);
            right = mid - 1;
        } 
        else {
            left = mid + 1;    
        }
    }
    
    return answer;
}