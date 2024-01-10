#include <string>
#include <vector>

using namespace std;

int extractDigit(int storey) {
    return storey % 10;
}

int nextDigit(int storey) {
    return ((storey % 100) - extractDigit(storey)) / 10;
}

int solution(int storey) {
    int answer = 0;
    
    while (storey != 0) {
        int digit = extractDigit(storey);
        
        if (0 <= digit && digit <= 4) {
            answer += digit;
            storey -= digit;
        }
        else if (6 <= digit && digit <= 9) {
            int rest = 10 - digit;
            
            answer += rest;
            storey += rest;
        }
        else {
            int next = nextDigit(storey);
            
            if (0 <= next && next <= 4) {
                storey -= 5;
                answer += 5;
            }
            else {
                storey += 5;
                answer += 5;
            }
        }
        
        storey /= 10;
    }
    
    return answer;
}