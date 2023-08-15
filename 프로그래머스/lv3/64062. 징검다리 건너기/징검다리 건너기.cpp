#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(vector<int>& stones, int mid, int k) {
    int cnt = 0;
    
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] < mid) {
            cnt++;
        }
        else {
            cnt = 0;
        }
        
        if (cnt >= k) {
            return false;
        }
    }
    
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int left = 1;
    int right = -1;
    
    for (int s : stones) {
        right = max(right, s);
    }
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (!possible(stones, mid, k)) {
            right = mid - 1;
        }
        else {
            answer = mid;
            left = mid + 1;
        }
    }
    
    return answer;
}