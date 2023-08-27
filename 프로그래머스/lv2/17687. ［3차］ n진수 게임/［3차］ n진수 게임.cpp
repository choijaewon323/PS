#include <string>
#include <vector>
#include <iostream>

using namespace std;

string convert(int num, int n) {
    string result = "";
    
    if (n >= 11) {
        while (num > 0) {
            int temp = num % n;
            
            string str = "";
            
            if (temp < 10) {
                str = to_string(temp);
            }
            else {
                switch (temp) {
                    case 10:
                        str += 'A';
                        break;
                    case 11:
                        str += 'B';
                        break;
                    case 12:
                        str += 'C';
                        break;
                    case 13:
                        str += 'D';
                        break;
                    case 14:
                        str += 'E';
                        break;
                    case 15:
                        str += 'F';
                }
            }
            
            result = str + result;
            num /= n;
        }
        
        return result;
    }
    
    while (num > 0) {
        result = to_string(num % n) + result;
        num /= n;
    }
    
    return result;
}

string numbers;

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    numbers += '0';
    
    int num = 1;
    while (numbers.size() <= 1500000) {
        numbers += convert(num, n);
        num++;
    }
    
    int start = p - 1;
    while (t > 0) {
        answer += numbers[start];
        start = start + m;
        
        t--;
    }
    
    return answer;
}