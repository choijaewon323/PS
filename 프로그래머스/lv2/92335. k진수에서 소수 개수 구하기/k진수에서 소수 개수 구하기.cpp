#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

string converter(int num, int k) {
    string result = "";
    
    if (num < k) {
        return to_string(num);
    }
    
    while (true) {
        if (num == 0) {
            break;
        }
        result += to_string(num % k);
        num /= k;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

vector<string> split(string str, char delimit) {
    stringstream ss(str);
    string temp;
    vector<string> result;
    while (getline(ss, temp, delimit)) {
        result.push_back(temp);
    }
    return result;
}

bool isPrime(long long n) {
    if (n == 1) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    
    if (n % 2 == 0) {
        return false;
    }
    
    for (int i = 3; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string num;
    
    if (k == 10) {
        num = to_string(n);
    } 
    else {
        num = converter(n, k);
    }
    
    vector<string> result = split(num, '0');
    
    for (string& p : result) {
        if (p == "") {
            continue;
        }
        
        bool prime = isPrime(stoll(p));
        
        if (prime) {
            answer++;
        }
    }
    
    return answer;
}