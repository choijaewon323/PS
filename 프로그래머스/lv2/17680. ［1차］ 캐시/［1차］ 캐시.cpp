#include <string>
#include <vector>
#include <deque>

using namespace std;

void toLower(string& input) {
    for (int i = 0; i < input.size(); i++) {
        char temp = input[i];
        
        if ('A' <= temp && temp <= 'Z') {
            input[i] += ('a' - 'A');
        }
    }
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    // base case
    if (cacheSize == 0) {
        return cities.size() * 5;
    }
    
    deque<string> cache;
    
    for (string& city : cities) {
        toLower(city);
        
        if (cache.empty()) {
            cache.push_back(city);
            answer += 5;
        }
        else if (cache.size() < cacheSize) {
            deque<string> tempCache;
            string hit = "";
            
            // 1. 찾기
            while (!cache.empty()) {
                string present = cache.front();
                cache.pop_front();
                
                if (present == city) {
                    hit = present;
                    break;
                }
                else {
                    tempCache.push_back(present);
                }
            }
            
            // 2. 원상복구
            while (!tempCache.empty()) {
                string present = tempCache.back();
                tempCache.pop_back();
                cache.push_front(present);
            }
            
            if (hit != "") {
                cache.push_back(hit);
                answer += 1;
            }
            else {
                cache.push_back(city);
                answer += 5;
            }
        }
        else {
            deque<string> tempCache;
            string hit = "";
            
            // 1. 찾기
            while (!cache.empty()) {
                string present = cache.front();
                cache.pop_front();
                
                if (present == city) {
                    hit = present;
                    break;
                }
                else {
                    tempCache.push_back(present);
                }
            }
            
            // 2. 원상복구
            while (!tempCache.empty()) {
                string present = tempCache.back();
                tempCache.pop_back();
                cache.push_front(present);
            }
            
            if (hit != "") {
                cache.push_back(hit);
                answer += 1;
            }
            else {
                cache.push_back(city);
                answer += 5;
                cache.pop_front();
            }
        }
    }
    
    return answer;
}