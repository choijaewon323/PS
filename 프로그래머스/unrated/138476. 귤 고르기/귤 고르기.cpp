#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> cnt;

bool compare(int a, int b) {
    if (cnt[a] == cnt[b]) {
        return a > b;
    }
    return cnt[a] > cnt[b];
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    // base case
    if (tangerine.size() == 1) {
        return 1;
    }
    
    for (int t : tangerine) {
        cnt[t]++;
    }
    
    sort(tangerine.begin(), tangerine.end(), compare);
    
    answer = 1;
    int first = tangerine[0];
    k--;
    for (int i = 1; i <= k; i++) {
        if (first != tangerine[i]) {
            first = tangerine[i];
            answer++;
        }
    }
    
    return answer;
}