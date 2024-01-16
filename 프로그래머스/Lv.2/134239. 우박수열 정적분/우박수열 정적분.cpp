#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> collatz(int number) {
    vector<int> results(1, number);
    
    while (number != 1) {
        if (number % 2 == 0) {
            number /= 2;
        }
        else {
            number = number * 3 + 1;
        }
        results.push_back(number);
    }
    
    return results;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<int> collatzNumbers = collatz(k);
    
    for (vector<int>& range : ranges) {
        int a = range[0];
        int b = range[1];
        
        b += collatzNumbers.size() - 1;
        
        if (a == b) {
            answer.push_back((double)0);
        }
        else if (a > b) {
            answer.push_back((double)-1);
        }
        else {
            double results = 0;
            for (int i = a + 1; i <= b; i++) {
                int prev = collatzNumbers[i - 1];
                int present = collatzNumbers[i];
                
                results += (prev + present) / 2.0;
            }
            
            answer.push_back(results);
        }
    }
    
    return answer;
}