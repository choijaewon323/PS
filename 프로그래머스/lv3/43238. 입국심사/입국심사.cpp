#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long people(vector<int>& times, long long mid) {
    long long result = 0;
    
    for (int& t : times) {
        result += (mid / t);
    }
    
    return result;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long left = 1;
    long long right = 1000000000000000000LL;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        
        long long result = people(times, mid);
        
        if (result >= n) {
            right = mid - 1;
            answer = mid;
        }
        else {
            left = mid + 1;
        }
    }
    
    return answer;
}