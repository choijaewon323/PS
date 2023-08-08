#include <string>
#include <vector>

using namespace std;

vector<int> dp[9];

int makeUpper(int n, int k) {
    string result = "";
    
    for (int i = 0; i < k; i++) {
        result += '0' + n;
    }
    
    return stoi(result);
}

int solution(int N, int number) {
    int answer = 0;
    
    dp[1].push_back(N);
    
    for (int i = 2; i <= 8; i++) {
        dp[i].push_back(makeUpper(N, i));
        
        for (int start = 1; start <= i; start++) {
            for (int end = 1; end <= i; end++) {
                if (start + end != i) {
                    continue;
                }
                
                for (int a : dp[start]) {
                    for (int b : dp[end]) {
                        dp[i].push_back(a + b);
                        dp[i].push_back(a - b);
                        dp[i].push_back(a * b);
                        
                        if (b != 0) {
                            dp[i].push_back(a / b);                            
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= 8; i++) {
        
        for (int d : dp[i]) {
            if (d == number) {
                return i;
            }
        }
    }
    
    return -1;
}