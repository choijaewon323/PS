#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int aIndex = 0;
    int bIndex = 0;
    
    while (aIndex < A.size() && bIndex < B.size()) {
        if (A[aIndex] < B[bIndex]) {
            answer++;
            aIndex++;
            bIndex++;
        }
        else {
            bIndex++;
        }
    }
    
    return answer;
}