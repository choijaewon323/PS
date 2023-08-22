#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int solution(vector<int> arr) {
    unsigned long long answer = 0;
    
    // base case
    if (arr.size() == 1) {
        return arr[0];
    }
    
    answer = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        int temp = gcd(answer, arr[i]);
        int lcm = answer * arr[i] / temp;
        answer = lcm;
    }
    
    
    return answer;
}