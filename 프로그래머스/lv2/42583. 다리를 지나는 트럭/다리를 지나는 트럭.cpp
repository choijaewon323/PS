#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    
    int currentLength = 0;
    int currentWeight = 0;
    int index = 0;
    queue<pair<int, int>> bridge;
    int arrived = 0;
    
    while (true)
    {
        if (arrived == truck_weights.size()) {
            break;
        }
        
        answer++;
        
        // push truck to bridge
        if (index < truck_weights.size()) {
            if (truck_weights[index] + currentWeight <= weight &&
               bridge.size() < bridge_length) 
            {
                bridge.push({truck_weights[index], bridge_length});
                currentWeight += truck_weights[index];
                index++;
            }
        }
        
        // bridge calculation
        int size = bridge.size();
        for (int i = 0; i < size; i++)
        {
            pair<int, int> truck = bridge.front();
            bridge.pop();
            
            truck.second--;
            
            if (truck.second == 0) {
                arrived++;
                currentWeight -= truck.first;
            }
            else
            {
                bridge.push(truck);
            }
        }
    }
    
    return answer + 1;
}