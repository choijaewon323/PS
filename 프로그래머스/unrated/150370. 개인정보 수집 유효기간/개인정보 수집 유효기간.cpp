#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

map<char, int> term;

vector<string> delimiter(string input, char delimit)
{
    stringstream is(input);
    string temp;
    vector<string> result;
    
    while (getline(is, temp, delimit))
    {
        result.push_back(temp);
    }
    
    return result;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    vector<string> todayStr = delimiter(today, '.');
    
    int todayYear = stoi(todayStr[0]);
    int todayMonth = stoi(todayStr[1]);
    int todayDate = stoi(todayStr[2]);
    
    for (string &t : terms)
    {
        vector<string> tempTerm = delimiter(t, ' ');
        
        term[tempTerm[0][0]] = stoi(tempTerm[1]);
    }
    
    for (int i = 0; i < privacies.size(); i++)
    {
        string privacy = privacies[i];
        vector<string> privacyStr = delimiter(privacy, ' ');
        vector<string> privacyDay = delimiter(privacyStr[0], '.');
        
        int priYear = stoi(privacyDay[0]);
        int priMonth = stoi(privacyDay[1]);
        int priDate = stoi(privacyDay[2]);
        int t = privacyStr[1][0];
        
        int termMonth = term[t];
        int addYear = termMonth / 12;
        int addMonth = termMonth % 12;
        
        // add
        priMonth += addMonth;
        
        if (priMonth > 12)
        {
            priYear += priMonth / 12;
            priMonth %= 12;
        }
        
        priYear += addYear;
        
        // sub
        priDate--;
        
        if (priDate == 0) {
            priDate = 28;
            priMonth--;
        }
        
        if (priMonth == 0) 
        {
            priMonth = 12;
            priYear--;
        }
        
        // compare
        /// year
        if (priYear > todayYear)
        {
            continue;
        }
        else if (priYear == todayYear)
        {
            if (priMonth > todayMonth)
            {
                continue;
            }
            else if (priMonth < todayMonth)
            {
                // expired
                answer.push_back(i + 1);
            }
            else
            {
                if (priDate >= todayDate)
                {
                    continue;
                }
                else
                {
                    // expired
                    answer.push_back(i + 1);
                }
            }
        }
        else
        {
            // expired
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}