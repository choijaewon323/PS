#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
    부분 수열 : x의 몇몇 원소들을 제거하거나 남은 원소들이 원래 순서를
    유지하여 얻을 수 있는 새로운 수열
    
    스타 수열
    - x의 길이가 2 이상의 짝수 (빈 수열 x)
    - x 길이를 2n이라 할 때, n개의 집합 {x0, x1}, {x2, x3}...
        의 교집합의 원소의 개수가 1 이상
    - 각 집합은 같은 숫자여서는 안된다.
    
    5 - 0, 4
    2 - 1
    3 - 2, 3, 5
    -----------
    
    0 - 0, 3 6 9
    3 - 1 2
    7 - 4
    2 - 5 7 8
*/
#define MAX 500000

int cnt[MAX];

int solution(vector<int> a)
{
    int answer = 0;
    for (int num : a)
    {
        cnt[num]++;
    }
    int size = a.size();
    for (int num = 0; num < size; num++)
    {
        if (answer >= cnt[num])
        {
            continue;
        }
        
        int temp = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (a[i] != a[i + 1] && (a[i] == num || a[i + 1] == num))
            {
                temp++;
                i++;
            }
        }
        answer = max(answer, temp);
    }
    return answer * 2;
}