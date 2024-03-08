#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 5000000

int cnt[MAX + 1];

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.first > b.first;
}

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer(starts.size());
    
    for (int i = 1; i <= e; i++) {
        for (int j = 1; j * i <= e; j++) {
            cnt[i * j]++;
        }
    }
    
    vector<pair<int, int>> numbers;
    int minStart = MAX + 1;
    int startSize = starts.size();
    for (int i = 0; i < startSize; i++) {
        int start = starts[i];
        
        minStart = min(minStart, start);
        numbers.push_back({start, i});
    }
    
    sort(numbers.begin(), numbers.end(), compare);
    
    int manyCnt = -1;
    int many = -1;
    int start = e;
    for (pair<int, int>& number : numbers) {
        int dest = number.first;
        int index = number.second;
        
        for ( ; start >= dest; start--) {
            if (cnt[start] >= manyCnt) {
                many = start;
                manyCnt = cnt[start];
            }
        }
        
        answer[index] = many;
    }
    
    return answer;
}