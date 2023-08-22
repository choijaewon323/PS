#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, bool> mp;

int solution(vector<int> elements) {
    int answer = 0;    
    
    int initAcc = 0;
    // 부분 수열 크기가 1인 경우, n인 경우
    for (int e : elements) {
        mp[e] = true;
        initAcc += e;
    }
    mp[initAcc] = true;
    
    // 부분 수열 크기가 2 ~ n - 1 까지인 경우
    int size = elements.size();
    
    for (int l = 2; l <= size - 1; l++) {
        int left = 0;
        int right = l - 1;
        int acc = 0;
        int cnt = size;
        
        // init
        for (int i = left; i <= right; i++) {
            acc += elements[i];
        }
        
        cnt--;
        
        while (cnt >= 0) {
            acc -= elements[left++];
            left %= size;
            right++;
            right %= size;
            acc += elements[right];
            
            mp[acc] = true;
            cnt--;
        }
    }
    
    answer = mp.size();
    
    return answer;
}