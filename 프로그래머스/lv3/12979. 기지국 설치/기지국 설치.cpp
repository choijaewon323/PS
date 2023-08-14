#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int now = 1;
    int stationIndex = 0;
    
    while (now <= n) {
        if (stationIndex >= stations.size() || now < stations[stationIndex] - w) {
            answer++;
            now = now + 2 * w + 1;
        }
        else {
            now = stations[stationIndex] + w + 1;
            stationIndex++;
        }
    }

    return answer;
}