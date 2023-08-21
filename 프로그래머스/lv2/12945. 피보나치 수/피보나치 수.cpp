#include <string>
#include <vector>

using namespace std;

#define MOD 1234567

int fib[100001];

int solution(int n) {
    int answer = 0;
    
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        fib[i] = (fib[i - 1] % MOD + fib[i - 2] % MOD) % MOD;
    }
    
    answer = fib[n];
    
    return answer;
}