#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> numbers;
    
    for (int i = 1; i <= n; i++) {
        numbers.push_back(i);
    }
    
    int left = 0;
    int right = 0;
    int acc = numbers[left];
    
    while (left <= right && right < n) {
        if (left != right) {
            if (acc < n) {  // 작을 때
                right++;
                if (right < n) {
                    acc += numbers[right];
                }
            }
            else if (acc > n) { // 클 때
                acc -= numbers[left];
                left++;
            }
            else {
                answer++;
                right++;
                if (right < n) {
                    acc += numbers[right];
                }
            }
        }
        else {
            if (acc == n) {
                answer++;
            }
            right++;
            if (right < n) {
                acc += numbers[right];
            }
        }
    }
    
    return answer;
}