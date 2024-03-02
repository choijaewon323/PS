#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <utility>
using namespace std;

/*
    N <= 2,000 이므로 O(N^2)이 가능하다.
    
    
*/

#define INTERVAL 999

vector<pair<int, int>> times;

vector<string> split(string input, char delimiter)
{
    stringstream ss(input);
    vector<string> result;
    string temp;
    while (getline(ss, temp, delimiter))
    {
        result.push_back(temp);
    }
    return result;
}

bool isInside(int originStart, int originEnd, int start, int end)
{
    if (end < originStart || originEnd < start)
    {
        return false;
    }
    return true;
}

int solution(vector<string> lines) 
{
    for (string line : lines)
    {
        vector<string> space = split(line, ' ');
        vector<string> hmsm = split(space[1], ':');
        vector<string> sm = split(hmsm[2], '.');
        int hour = stoi(hmsm[0]) * 60 * 60 * 1000;
        int minute = stoi(hmsm[1]) * 60 * 1000;
        int second = stoi(sm[0]) * 1000;
        int millie = stoi(sm[1]);
        double tDouble = stod(space[2].substr(0, space[2].size() - 1));
        int t = (int)(tDouble * 1000);
        int startTime = hour + minute + second + millie - (t - 1);
        int endTime = hour + minute + second + millie;
        times.push_back({startTime, endTime});
    }
    int answer = 1;
    for (int i = 0; i < times.size(); i++)
    {
        int presentStart = times[i].first;
        int presentEnd = times[i].second;
        int leftStart = 1;
        int startRight = 1;
        int leftEnd = 1;
        int endRight = 1;
        int temp = 0;
        for (int j = 0; j < times.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            int tempStart = times[j].first;
            int tempEnd = times[j].second;
            // 1. left start
            if (isInside(presentStart - INTERVAL, presentStart, tempStart, tempEnd))
            {
                leftStart++;
            }
            // 2. start right
            if (isInside(presentStart, presentStart + INTERVAL, tempStart, tempEnd))
            {
                startRight++;
            }
            // 3. left end
            if (isInside(presentEnd - INTERVAL, presentEnd, tempStart, tempEnd))
            {
                leftEnd++;
            }
            // 4. end right
            if (isInside(presentEnd, presentEnd + INTERVAL, tempStart, tempEnd))
            {
                endRight++;
            }
        }
        
        temp = max(max(leftStart, startRight), max(leftEnd, endRight));
        answer = max(answer, temp);
    }
    return answer;
}