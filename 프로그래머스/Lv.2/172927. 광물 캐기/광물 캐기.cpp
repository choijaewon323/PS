#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    남아있는 [dia, iron, stone] 세트에 대해 몇번째 미네랄을 캐냐
    이게 현재 상태로 볼 수 있고, 각 상태는 서로 독립적이다.
    
    5 * 5 * 5 * 50 = 6250 이므로 충분히 DP 배열 생성 가능하다.
*/

#define DIA 0
#define IRON 1
#define STONE 2

#define INF 1000000000

int fatique(int pick, string mineral) {
    switch (pick) {
        case DIA:
            if (mineral == "diamond") {
                return 1;
            }
            else if (mineral == "iron") {
                return 1;
            }
            else {
                return 1;
            }
            break;
        case IRON:
            if (mineral == "diamond") {
                return 5;
            }
            else if (mineral == "iron") {
                return 1;
            }
            else {
                return 1;
            }
            break;
        case STONE:
            if (mineral == "diamond") {
                return 25;
            }
            else if (mineral == "iron") {
                return 5;
            }
            else {
                return 1;
            }
            break;
    }
    
    return -1;
}

int solve(vector<string>& minerals, int dia, int iron, int stone, int index) {
    if (index >= minerals.size()) {
        return 0;
    }
    
    if (dia == 0 && iron == 0 && stone == 0) {
        return 0;
    }
    
    int diaFat = INF;
    int ironFat = INF;
    int stoneFat = INF;
    // 1. dia
    if (dia > 0) {
        diaFat = 0;
        int i;
        for (i = index; i < index + 5; i++) {
            if (i >= minerals.size()) {
                continue;
            }
            
            diaFat += fatique(DIA, minerals[i]);
        }
        
        diaFat += solve(minerals, dia - 1, iron, stone, i);
    }
    
    // 2. iron
    if (iron > 0) {
        ironFat = 0;
        int i;
        for (i = index; i < index + 5; i++) {
            if (i >= minerals.size()) {
                continue;
            }
            
            ironFat += fatique(IRON, minerals[i]);
        }
        
        ironFat += solve(minerals, dia, iron - 1, stone, i);
    }
    
    // 3. stone
    if (stone > 0) {
        stoneFat = 0;
        int i;
        for (i = index; i < index + 5; i++) {
            if (i >= minerals.size()) {
                continue;
            }
            
            stoneFat += fatique(STONE, minerals[i]);
        }
        
        stoneFat += solve(minerals, dia, iron, stone - 1, i);
    }
    
    return min(diaFat, min(ironFat, stoneFat));
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    int dia = picks[0];
    int iron = picks[1];
    int stone = picks[2];
    
    answer = solve(minerals, dia, iron, stone, 0);
    
    return answer;
}