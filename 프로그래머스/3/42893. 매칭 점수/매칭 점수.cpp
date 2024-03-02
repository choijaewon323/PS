#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

/*
    한 웹페이지 -> 기본 점수, 외부 링크 수, 링크 점수, 매칭 점수 구할 수 있음
    
    기본 점수 : 대소문자 무시, 검색어가 등장하는 횟수
    외부 링크 수 : 해당 웹페이지에서 다른 외부 페이지로 연결된 링크의 수
    링크 점수 : 해당 웹페이지로 링크가 걸린 다른 웹 페이지의 기본 점수 / 외부 링크 수의 총합
    매칭 점수 : 기본 점수 + 링크 점수
    
    
*/

char toLower(char c)
{
    if ('A' <= c && c <= 'Z')
    {
        return c + ('a' - 'A');
    }
    else
    {
        return c;
    }
}

vector<string> split(string input)
{
    vector<string> result;
    string temp = "";
    for (char c : input)
    {
        if ('a' <= c && c <= 'z')
        {
            temp += c;
        }
        else
        {
            if (!temp.empty())
            {
                result.push_back(temp);
            }
            temp = "";
        }
    }
    if (!temp.empty())
    {
        result.push_back(temp);
    }
    return result;
}

vector<int> getPi(string comp)
{
    int m = comp.size();
    vector<int> pi(m, 0);
    int start = 1;
    int matched = 0;
    while (start + matched < m)
    {
        if (comp[start + matched] == comp[matched])
        {
            matched++;
            pi[start + matched - 1] = matched;
        }
        else
        {
            if (matched == 0)
            {
                start++;
            }
            else
            {
                start += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

vector<int> kmp(string all, string comp)
{
    int n = all.size();
    int m = comp.size();
    vector<int> pi = getPi(comp);
    vector<int> result;
    int start = 0;
    int matched = 0;
    while (start <= n - m)
    {
        if (matched < m && all[start + matched] == comp[matched])
        {
            matched++;
            if (matched == m)
            {
                result.push_back(start);
            }
        }
        else
        {
            if (matched == 0)
            {
                start++;
            }
            else
            {
                start += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return result;
}

string getUrl(int index, string& page)
{
    string result = "";
    for (int i = index; page[i] != '\"'; i++)
    {
        result += page[i];
    }
    return result;
}

struct Node
{
    string url = "";
    int base = 0;
    int outer = 0;
    double link = 0;
    double matching = 0;
};
    
map<string, int> urlToIndex;
map<string, vector<int>> links;
vector<Node> nodes;

string getMyUrl(string page)
{
    vector<int> urlIndex = kmp(page, "<meta property=\"og:url\" content=\"");
    string myUrl = getUrl(urlIndex[0] + 33, page);
    return myUrl;
}

int calculateBase(string page, string word)
{
    vector<string> words = split(page);
    int base = 0;
    for (string& w : words)
    {
        if (w == word)
        {
            base++;
        }
    }
    return base;
}

int calculateOuter(string page, int me)
{
    vector<int> urlIndex = kmp(page, "<a href=\"");
    int outer = urlIndex.size();
    for (int i = 0; i < urlIndex.size(); i++)
    {
        string url = getUrl(urlIndex[i] + 9, page);
        links[url].push_back(me);
    }
    
    return outer;
}

void allLower(string& word)
{
    for (int i = 0; i < word.size(); i++)
    {
        word[i] = toLower(word[i]);
    }
}

int solution(string word, vector<string> pages) 
{   
    int answer = 0;
    
    allLower(word);
    
    for (int i = 0; i < pages.size(); i++)
    {
        string& page = pages[i];
        
        allLower(page);
        
        string myUrl = getMyUrl(page);
        
        urlToIndex[myUrl] = i;
        
        int base = calculateBase(page, word);
        
        int outer = calculateOuter(page, i);
        
        nodes.push_back({myUrl, base, outer, 0, 0});
    }
    
    double maxValue = -1;
    for (int i = 0; i < pages.size(); i++)
    {
        Node presentNode = nodes[i];
        string myUrl = presentNode.url;
        double linkScore = 0;
        
        for (int link : links[myUrl])
        {
            Node nextNode = nodes[link];
            linkScore += (double)(nextNode.base) / (nextNode.outer);
        }
        if (maxValue < linkScore + presentNode.base)
        {
            maxValue = linkScore + presentNode.base;
            answer = i;
        }
    }
    
    return answer;
}