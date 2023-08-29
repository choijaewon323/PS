#include <string>
#include <vector>

using namespace std;

string convert(long long number) {
    if (number == 0) {
        return "0";
    }
    
    string result = "";
    
    while (number > 0) {
        result = to_string(number % 2) + result;
        number /= 2;
    }
    
    return result;
}

long long pow[51];

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    long long temp = 1;
    
    for (int i = 0; i < 51; i++) {
        pow[i] = temp;
        temp *= 2;
    }
    
    for (long long number : numbers) {
        string present = convert(number);
        
        if (present[present.size() - 1] == '0') {
            answer.push_back(number + 1);
            continue;
        }
        
        int indexOfZero = -1;
        for (int i = present.size() - 1; i >= 0; i--) {
            if (present[i] == '0') {
                indexOfZero = i;
                break;
            }
        }
        
        if (indexOfZero == -1) { // 모든 수가 1인 경우
            present = '1' + present;
            present[1] = '0';
            
            // 숫자로 변경
            long long result = 0;
            for (int i = 0; i < present.size(); i++) {
                result += (present[i] - '0') * pow[present.size() - i - 1];
            }
            answer.push_back(result);
            
            continue;
        }
        
        present[indexOfZero] = '1';
        present[indexOfZero + 1] = '0';
        
        // 숫자로 변경
        long long result = 0;
        for (int i = 0; i < present.size(); i++) {
            result += (present[i] - '0') * pow[present.size() - i - 1];
        }
        answer.push_back(result);
    }
    
    return answer;
}