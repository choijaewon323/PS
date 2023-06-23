#include <string>
#include <vector>
#include <map>

using namespace std;

#define MAX 9999999

bool isPrime[MAX + 1];
map<int, int> m;

void makePrime()
{
    for (int i = 2; i <= MAX; i++)
    {
        isPrime[i] = true;
    }
    
    for (int i = 2; i * i <= MAX; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

void primeDecision(int num)
{
    if (isPrime[num])
    {
        m[num]++;
    }
}

void func(string& numbers, int index, string res, vector<bool>& used)
{
    if (index == numbers.size())
    {
        if (res.empty())
        {
            return;
        }
        
        int temp = stoi(res);
        
        primeDecision(temp);
        
        return;
    }
    func(numbers, index + 1, res, used);
    
    for (int i = 0; i < numbers.size(); i++)
    {
        if (!used[i])
        {
            used[i] = true;
            func(numbers, index + 1, res + numbers[i], used);
            used[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    string res = "";
    vector<bool> used(numbers.size(), false);
    
    makePrime();
    func(numbers, 0, res, used);
    
    answer = m.size();
    
    return answer;
}