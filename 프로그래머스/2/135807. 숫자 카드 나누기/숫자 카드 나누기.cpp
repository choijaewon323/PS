#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    주어진 수를 모두 나눌 수 있다 -> 최대공약수
    
*/

int gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    
    if (b == 0) {
        return a;
    }
    
    return gcd(b, a % b);
}

int findGcd(vector<int>& arr) {
    int result = arr[0];
    
    int size = arr.size();
    for (int i = 1; i < size; i++) {
        result = gcd(result, arr[i]);
    }
    
    return result;
}

int nonDividable(int number, vector<int>& target) {
    for (int temp : target) {
        if (temp % number == 0) {
            return 0;
        }
    }
    
    return number;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int gcdA = findGcd(arrayA);
    int gcdB = findGcd(arrayB);
    
    int answer1 = nonDividable(gcdA, arrayB);
    int answer2 = nonDividable(gcdB, arrayA);
    
    return max(answer1, answer2);
}