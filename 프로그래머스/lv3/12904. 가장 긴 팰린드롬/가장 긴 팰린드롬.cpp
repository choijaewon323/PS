#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int palindrome(string& s, int start, int end) {
    int left = start;
    int right = end - 1;
    
    while (left <= right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        }
        else {
            return -1;
        }
    }
    
    return end - start;
}

int solution(string s) {
    int answer = 0;
    
    for (int cnt = s.size(); cnt >= 1; cnt--) {
        int last = s.size() - cnt;
        
        for (int i = 0; i <= last; i++) {
            int start = i;
            int end = i + cnt;
            
            int result = palindrome(s, start, end);
            
            if (result != -1) {
                return result;
            }
        }
    }

    return answer;
}