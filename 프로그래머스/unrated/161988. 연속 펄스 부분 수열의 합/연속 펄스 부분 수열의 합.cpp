#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long dp1[500000];
long long dp2[500000];

long long solution(vector<int> sequence) {
    long long answer = -50000000000;
    
    vector<long long> seq1;
    vector<long long> seq2;
    
    int start = 1;
    for (int s : sequence) {
        seq1.push_back(s * start);
        seq2.push_back(s * start * -1);
        start *= -1;
    }
    
    dp1[0] = seq1[0];
    dp2[0] = seq2[0];
    
    for (int i = 1; i < sequence.size(); i++) {
        dp1[i] = max(dp1[i - 1] + seq1[i], seq1[i]);
        dp2[i] = max(dp2[i - 1] + seq2[i], seq2[i]);
    }
    
    for (int i = 0; i < sequence.size(); i++) {
        answer = max(answer, max(dp1[i], dp2[i]));
    }
    
    return answer;
}