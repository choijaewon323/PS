#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int left = 0;
    int right = 0;
    int acc = sequence[left];
    
    int answerLeft = -1;
    int answerRight = -1;
    int answerLength = 1000000001;
    
    while (right < sequence.size()) {
        if (left == right) {
            if (acc == k) {
                if (answerLength > right - left + 1) {
                    answerLength = right - left + 1;
                    answerLeft = left;
                    answerRight = right;
                }
                else if (answerLength == right - left + 1) {
                    answerLeft = min(answerLeft, left);
                    answerRight = min(answerRight, right);
                }
                
                if (right + 1 < sequence.size()) {
                    left++;
                    right++;
                    acc = sequence[right];
                }
                else {
                    break;
                }
            }
            else {
                right++;
                if (right < sequence.size()) {
                    acc += sequence[right];
                }
            }
        }
        else {
            if (acc < k) {
                right++;
                if (right < sequence.size()) {
                    acc += sequence[right];
                }
            }
            else if (acc > k) {
                acc -= sequence[left];
                left++;
            }
            else {
                if (answerLength > right - left + 1) {
                    answerLength = right - left + 1;
                    answerLeft = left;
                    answerRight = right;
                }
                else if (answerLength == right - left + 1) {
                    answerLeft = min(answerLeft, left);
                    answerRight = min(answerRight, right);
                }
                
                acc -= sequence[left];
                left++;
                right++;
                if (right < sequence.size()) {
                    acc += sequence[right];
                }
            }
        }
    }
    
    answer.push_back(answerLeft);
    answer.push_back(answerRight);
    
    return answer;
}