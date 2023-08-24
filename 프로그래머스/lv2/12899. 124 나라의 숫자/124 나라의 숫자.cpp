#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while (n > 0) {
        int rem = n % 3;
        n /= 3;
        
        if (rem == 0) {
            answer = '4' + answer;
            n--;
        }
        else if (rem == 1) {
            answer = '1' + answer;
        }
        else if (rem == 2) {
            answer = '2' + answer;
        }
    }
    
    
    return answer;
}