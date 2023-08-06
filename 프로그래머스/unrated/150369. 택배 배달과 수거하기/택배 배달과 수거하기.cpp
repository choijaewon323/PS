#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int deliver = 0;
    int pickup = 0;
    
    for (int i = n - 1; i >= 0; i--)
    {
        if (deliveries[i] > 0 || pickups[i] > 0)
        {
            int cnt = 0;
            
            while (deliver < deliveries[i] || pickup < pickups[i])
            {
                cnt++;
                deliver += cap;
                pickup += cap;
            }
            
            deliver -= deliveries[i];
            pickup -= pickups[i];
            answer += (i + 1) * cnt * 2;
        }
    }
    
    return answer;
}