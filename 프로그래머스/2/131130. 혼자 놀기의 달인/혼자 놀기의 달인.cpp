#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100

int card[MAX + 1];
int maxSize;

void init(vector<int>& cards) {
    for (int i = 0; i < cards.size(); i++) {
        card[i + 1] = cards[i];
    }
}

int makeGroup(vector<bool>& isGrouped, int start) {
    int present = start;
    int result = 0;
    
    while (!isGrouped[present]) {
        result++;
        isGrouped[present] = true;
        int next = card[present];
        present = next;
    }
    
    return result;
}

vector<int> makeGroupList() {
    vector<int> results;
    vector<bool> isGrouped(maxSize + 1, false);
    
    for (int i = 1; i <= maxSize; i++) {
        if (!isGrouped[i]) {
            int temp = makeGroup(isGrouped, i);
            
            results.push_back(temp);
        }
    }
    
    return results;
}

int solution(vector<int> cards) {
    int answer = 0;
    
    maxSize = cards.size();
    init(cards);
    
    vector<int> results = makeGroupList();
    
    sort(results.begin(), results.end(), greater<int>());
    
    if (results.size() == 1) {
        return 0;
    }
    
    answer = results[0] * results[1];
    
    return answer;
}