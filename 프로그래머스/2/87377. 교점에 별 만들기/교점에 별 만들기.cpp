#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

/*
    Ax + By + C = 0으로 표현 가능한 n개의 직선 줌
    
    교점 중 정수 좌표에 별을 그린다.
    
    모든 별을 포함하는 최소한의 크기로만 표현해야함
    
    최대 1,000개의 line 중 2개를 선택 -> 10C2 = 499,500번
    
    가장 높은 좌표, 가장 낮은 좌표, 가장 왼쪽 좌표, 가장 오른쪽 좌표를 각자 저장
    
    그 안에서 루프 돌려서 표현하면 될듯
    
    정답은 무조건 1,000,000 개 이내에서 표현됨
    
    정수 좌표이므로 x, y 수식 중 어느 것이라도 나누어떨어지지 않으면
    소수인 것
*/

using namespace std;

#define NO_MEET 100000000000000ll
typedef long long LL;
map<pair<LL, LL>, bool> stars;

pair<LL, LL> calculate(vector<int>& abe, vector<int>& cdf)
{
    LL a = abe[0];
    LL b = abe[1];
    LL e = abe[2];
    LL c = cdf[0];
    LL d = cdf[1];
    LL f = cdf[2];
    LL ad_bc = a*d - b*c;
    if (ad_bc == 0)
    {
        return {NO_MEET, NO_MEET};
    }
    LL bf_ed = b*f - e*d;
    LL ec_af = e*c - a*f;
    if (bf_ed % ad_bc != 0 || ec_af % ad_bc != 0)
    {
        return {NO_MEET, NO_MEET};
    }
    LL y = ec_af / ad_bc;
    LL x = bf_ed / ad_bc;
    return {y, x};
}

vector<string> solution(vector<vector<int>> line) 
{
    LL up = -NO_MEET;
    LL down = NO_MEET;
    LL left = NO_MEET;
    LL right = -NO_MEET;
    LL allSize = line.size();
    for (int i = 0; i < allSize; i++)
    {
        for (int j = i + 1; j < allSize; j++)
        {
            vector<int> abe = line[i];
            vector<int> cdf = line[j];
            pair<LL, LL> result = calculate(abe, cdf);
            if (result.first == NO_MEET && result.second == NO_MEET)
            {
                continue;
            }
            LL y = result.first;
            LL x = result.second;
            up = max(up, y);
            down = min(down, y);
            left = min(left, x);
            right = max(right, x);
            stars[result] = true;
        }
    }
    vector<string> answer;
    for (LL y = up; y >= down; y--)
    {
        string temp = "";
        for (LL x = left; x <= right; x++)
        {
            if (stars[{y, x}])
            {
                temp += '*';
            }
            else
            {
                temp += '.';
            }
        }
        answer.push_back(temp);
    }
    return answer;
}