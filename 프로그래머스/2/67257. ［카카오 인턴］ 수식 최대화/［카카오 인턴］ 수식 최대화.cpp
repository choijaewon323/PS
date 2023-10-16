#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<char> used;

long long solve(vector<int> temp, vector<bool> tempUsed, vector<long long> numbers, vector<char> opers) {
    if (temp.size() == used.size()) {
        for (int i = 0; i < temp.size(); i++) {
            char oper = used[temp[i]];
            
            if (oper == '*') {
                long long first = numbers[0];
                vector<long long> tempNum;
                vector<char> tempOper;
                
                for (int j = 1; j < numbers.size(); j++) {
                    long long second = numbers[j];
                    
                    if (opers[j - 1] != oper) {
                        tempOper.push_back(opers[j - 1]);
                        tempNum.push_back(first);
                        first = second;
                    }
                    else {
                        long long tempResult = first * second;
                        first = tempResult;
                    }
                }
                
                tempNum.push_back(first);
                
                numbers = tempNum;
                opers = tempOper;
            }
            else if (oper == '+') {
                long long first = numbers[0];
                vector<long long> tempNum;
                vector<char> tempOper;
                
                for (int j = 1; j < numbers.size(); j++) {
                    long long second = numbers[j];
                    
                    if (opers[j - 1] != oper) {
                        tempOper.push_back(opers[j - 1]);
                        tempNum.push_back(first);
                        first = second;
                    }
                    else {
                        long long tempResult = first + second;
                        first = tempResult;
                    }
                }
                
                tempNum.push_back(first);
                
                numbers = tempNum;
                opers = tempOper;
            }
            else if (oper == '-') {
                long long first = numbers[0];
                vector<long long> tempNum;
                vector<char> tempOper;
                
                for (int j = 1; j < numbers.size(); j++) {
                    long long second = numbers[j];
                    
                    if (opers[j - 1] != oper) {
                        tempOper.push_back(opers[j - 1]);
                        tempNum.push_back(first);
                        first = second;
                    }
                    else {
                        long long tempResult = first - second;
                        first = tempResult;
                    }
                }
                
                tempNum.push_back(first);
                
                numbers = tempNum;
                opers = tempOper;
            }
        }
        
        long long result = numbers[0];
        
        if (result < 0) {
            result = -result;
        }
        
        return result;
    }
    
    long long result = -1;
    for (int i = 0; i < used.size(); i++) {
        if (!tempUsed[i]) {
            temp.push_back(i);
            tempUsed[i] = true;
            result = max(result, solve(temp, tempUsed, numbers, opers));
            tempUsed[i] = false;
            temp.pop_back();
        }
    }
    
    return result;
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<long long> numbers;
    vector<char> opers;
    
    map<char, bool> mp;
    int expSize = expression.size();
    string number = "";
    for (int i = 0; i < expSize; i++) {
        char c = expression[i];
        
        if ('0' <= c && c <= '9') {
            number += c;
        }
        else {  // operator
            if (mp[c] == false) {
                used.push_back(c);
            }
            opers.push_back(c); 
            mp[c] = true;
            
            numbers.push_back(stoll(number));
            number = "";
        }
    }
    
    if (opers.size() == 1) {
        long long result;
        if (opers[0] == '-') {
            result = numbers[0] - numbers[1];
        }
        else if (opers[0] == '+') {
            result = numbers[0] + numbers[1];
        }
        else {
            result = numbers[0] * numbers[1];
        }
        
        if (result < 0) {
            result = -result;
        }
        
        return result;
    }
    
    numbers.push_back(stoll(number));
    
    answer = solve(vector<int>(), vector<bool>(mp.size(), false), numbers, opers);
    
    return answer;
}