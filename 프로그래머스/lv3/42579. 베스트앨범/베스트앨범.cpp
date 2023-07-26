#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> playCnt;

vector<string> globalGenres;
vector<int> globalPlays;

bool compare(int a, int b)
{
    if (globalGenres[a] == globalGenres[b] && globalPlays[a] == globalPlays[b])
    {
        return a < b;
    }
    if (globalGenres[a] == globalGenres[b])
    {
        return globalPlays[a] > globalPlays[b];
    }
    return playCnt[globalGenres[a]] > playCnt[globalGenres[b]];
}

map<string, int> answerCnt;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    globalGenres = genres;
    globalPlays = plays;
    
    // genre play count calculation
    for (int i = 0; i < genres.size(); i++)
    {
        playCnt[genres[i]] += plays[i];
        answer.push_back(i);
    }
    
    sort(answer.begin(), answer.end(), compare);
    
    vector<int> tempAnswer;
    
    for (int a : answer)
    {
        if (answerCnt[genres[a]] < 2)
        {
            answerCnt[genres[a]]++;
            tempAnswer.push_back(a);
        }
    }

    return tempAnswer;
}