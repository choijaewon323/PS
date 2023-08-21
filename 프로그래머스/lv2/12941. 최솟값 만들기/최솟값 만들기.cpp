#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    
    int length = A.size();
    
    for (int i = 0; i < length; i++) {
        int a = A[i];
        int b = B[i];
        
        answer += a * b;
    }
    
    return answer;
}