#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 500
#define INF 2000000000

int dist[MAX + 1][MAX + 1];
vector<vector<int>> problems;
int maxAlgo;
int maxCoding;

void init()
{
    for (int y = 0; y <= MAX; y++)
    {
        for (int x = 0; x <= MAX; x++)
        {
            dist[y][x] = INF;
        }
    }
}

int solve(int algo, int coding)
{
    if (algo >= maxAlgo && coding >= maxCoding)
    {
        return 0;
    }
    if (algo >= maxAlgo)
    {
        algo = maxAlgo;
    }
    if (coding >= maxCoding)
    {
        coding = maxCoding;
    }
    dist[algo][coding] = 0;
    for (int i = algo; i <= maxAlgo; i++)
    {
        for (int j = coding; j <= maxCoding; j++)
        {
            dist[i + 1][j] = min(dist[i + 1][j], dist[i][j] + 1);
            dist[i][j + 1] = min(dist[i][j + 1], dist[i][j] + 1);   
            
            for (vector<int>& problem : problems)
            {
                int algoReq = problem[0];
                int codingReq = problem[1];
                int algoRes = problem[2];
                int codingRes = problem[3];
                int cost = problem[4];

                if (i >= algoReq && j >= codingReq)
                {
                    int nextAlgo = i + algoRes;
                    int nextCoding = j + codingRes;
                    int nextCost = dist[i][j] + cost;
                    
                    if (nextAlgo > maxAlgo)
                    {
                        nextAlgo = maxAlgo;
                    }
                    
                    if (nextCoding > maxCoding)
                    {
                        nextCoding = maxCoding;
                    }

                    dist[nextAlgo][nextCoding] = min(dist[nextAlgo][nextCoding], nextCost);
                }
            }
        }
    }
    
    return dist[maxAlgo][maxCoding];
}

int solution(int alp, int cop, vector<vector<int>> probs) 
{
    init();
    problems = probs;
    for (vector<int>& problem : problems)
    {
        int algoReq = problem[0];
        int codingReq = problem[1];
        
        maxAlgo = max(maxAlgo, algoReq);
        maxCoding = max(maxCoding, codingReq);
    }
    int answer = solve(alp, cop);
    return answer;
}