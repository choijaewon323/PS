#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first;
}

int solution(vector<vector<int> > land) {
    int answer = 0;

    // base case
    if (land.size() == 1) {
        for (int l : land[0]) {
            answer = max(answer, l);
        }
        return answer;
    }
    
    for (int row = 1; row < land.size(); row++) {
        vector<pair<int, int>> last;
        
        for (int i = 0; i < 4; i++) {
            last.push_back({land[row - 1][i], i});
        }
        
        sort(last.begin(), last.end(), compare);
        
        for (int i = 0; i < 4; i++) {
            if (last[3].second != i) {
                land[row][i] += last[3].first;
            }
            else {
                land[row][i] += last[2].first;
            }
        }
    }
    
    for (int i = 0; i < 4; i++) {
        answer = max(answer, land[land.size() - 1][i]);
    }
    
    return answer;
}