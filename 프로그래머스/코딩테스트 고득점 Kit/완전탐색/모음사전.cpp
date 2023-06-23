#include <string>
#include <vector>

using namespace std;

vector<string> words;
char alphabet[5] = {'A', 'E', 'I', 'O', 'U'};

void func(int index, string temp)
{
    if (index == 5)
    {
        return;
    }
    
    for (int i = 0; i < 5; i++)
    {
        words.push_back(temp + alphabet[i]);
        func(index + 1, temp + alphabet[i]);
    }
}

int solution(string word) {
    int answer = 0;
    string temp = "";
    
    func(0, temp);
    
    for (int i = 0; i < words.size(); i++)
    {
        if (word == words[i])
        {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}