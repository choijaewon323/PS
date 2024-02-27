#include <string>
#include <vector>

using namespace std;

/*
    n개의 동일한 작업
    
    1 2 3 코어
    
    6 - 3 = 3
    
    0시간 -> 0 / 1, 0 / 2, 0 / 3 = 0 0 0 - 0
    1시간 -> 1 / 1, 1 / 2, 1 / 3 = 1 0 0 - 1
    2시간 -> 2 / 1, 2 / 2, 2 / 3 = 2 1 0 - 3
    3시간 -> 3 / 1, 3 / 2, 3 / 3 = 3 1 1 - 5
    4시간 -> 4 / 1, 4 / 2, 4 / 3 = 4 2 1 - 7
    
    lower bound를 이용하여 몇시간 후일 때 해당 작업이 들어가는 지 알 수 있다.
    
    근데 정확히 어떤 코어에서 하는지는 어떻게 발견하지?
    
    바로 1시간 전을 찾은 뒤 빼줌 -> 1이 있는 곳이 지금 막 끝난 곳
    
*/

typedef long long ll;

ll calculate(int mid, vector<int> cores)
{
    ll result = 0;
    for (int core : cores)
    {
        result += mid / core;
    }
    return result;
}

int lowerBound(int n, vector<int> cores)
{
    ll dest = n;
    int left = 0;
    int right = 500000000;
    int result = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (calculate(mid, cores) >= dest)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return result;
}

vector<int> getArr(int time, vector<int> cores)
{
    vector<int> result;
    for (int core : cores)
    {
        result.push_back(time / core);
    }
    return result;
}

int solution(int n, vector<int> cores) {
    if (n == 0)
    {
        return 1;
    }
    if (n <= cores.size())
    {
        return n;
    }
    n -= cores.size();
    int time = lowerBound(n, cores);
    vector<int> present = getArr(time, cores);
    vector<int> prev = getArr(time - 1, cores);
    ll prevCnt = calculate(time - 1, cores);
    int size = present.size();
    for (int i = 0; i < size; i++)
    {
        present[i] -= prev[i];
    }
    ll answer = prevCnt;
    for (int i = 0; i < size; i++)
    {
        answer += present[i];
        if (answer == n)
        {
            return i + 1;
        }
    }
    return answer;
}