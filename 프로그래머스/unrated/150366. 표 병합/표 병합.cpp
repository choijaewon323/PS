#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <utility>

using namespace std;

string cell[51][51];

map<pair<int, int>, pair<int, int>> parent;

void init()
{
    for (int y = 0; y < 51; y++)
    {
        for (int x = 0; x < 51; x++)
        {
            cell[y][x] = "";
            parent[{y, x}] = {y, x};
        }
    }
}

pair<int, int> find(pair<int, int> x)
{
    if (x != parent[x])
    {
        return parent[x] = find(parent[x]);
    }
    return x;
}

void merge(pair<int, int> a, pair<int, int> b)
{
    pair<int, int> aRoot = find(a);
    pair<int, int> bRoot = find(b);
    
    if (aRoot == bRoot)
    {
        return;
    }
    
    if (aRoot > bRoot)
    {
        parent[aRoot] = bRoot;
    }
    else
    {
        parent[bRoot] = aRoot;
    }
}

vector<string> split(string str, char delim)
{
    stringstream ss(str);
    string temp;
    vector<string> result;
    
    while (getline(ss, temp, delim))
    {
        result.push_back(temp);
    }
    
    return result;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    // initialization
    init();
    
    for (string &command : commands)
    {
        vector<string> splitCommand = split(command, ' ');
        
        if (splitCommand[0] == "UPDATE")
        {
            if (splitCommand.size() == 4)
            {
                int r = stoi(splitCommand[1]);
                int c = stoi(splitCommand[2]);
                string value = splitCommand[3];
                
                pair<int, int> ce = find({r, c});
                cell[ce.first][ce.second] = value;
            }
            else if (splitCommand.size() == 3)
            {
                string value1 = splitCommand[1];
                string value2 = splitCommand[2];
                
                for (int y = 1; y <= 50; y++)
                {
                    for (int x = 1; x <= 50; x++)
                    {
                        pair<int, int> temp = find({y, x});
                        if (cell[temp.first][temp.second] == value1)
                        {
                            cell[temp.first][temp.second] = value2;
                        }
                    }
                }
            }
        }
        else if (splitCommand[0] == "MERGE")
        {
            int r1 = stoi(splitCommand[1]);
            int c1 = stoi(splitCommand[2]);
            int r2 = stoi(splitCommand[3]);
            int c2 = stoi(splitCommand[4]);
            
            // completely same
            if (r1 == r2 && c1 == c2)
            {
                continue;
            }
            
            pair<int, int> a = find({r1, c1});
            pair<int, int> b = find({r2, c2});
            
            // same cell
            if (a == b)
            {
                continue;
            }
            
            string value;
            if (cell[a.first][a.second] == "" && cell[b.first][b.second] == "")
            {
                value = "";
            }
            else if (cell[a.first][a.second] != "" && cell[b.first][b.second] == "")
            {
                value = cell[a.first][a.second];
            }
            else if (cell[a.first][a.second] == "" && cell[b.first][b.second] != "")
            {
                value = cell[b.first][b.second];
            }
            else
            {
                value = cell[a.first][a.second];
            }
            
            merge(a, b);
            pair<int, int> result = find(a);
            cell[result.first][result.second] = value;
        }
        else if (splitCommand[0] == "UNMERGE")
        {
            int r = stoi(splitCommand[1]);
            int c = stoi(splitCommand[2]);
            
            pair<int, int> temp = find({r, c});
            
            string value = cell[temp.first][temp.second];
            
            vector<pair<int, int>> temps;
            
            for (int y = 1; y <= 50; y++)
            {
                for (int x = 1; x <= 50; x++)
                {
                    if (find({y, x}) == temp)
                    {
                        temps.push_back({y, x});
                    }
                }
            }
            
            for (pair<int, int>& t : temps)
            {
                parent[t] = {t.first, t.second};
                cell[t.first][t.second] = "";
            }
            
            temp = find({r, c});
            cell[temp.first][temp.second] = value;
        }
        else if (splitCommand[0] == "PRINT")
        {
            int r = stoi(splitCommand[1]);
            int c = stoi(splitCommand[2]);
            
            pair<int, int> temp = find({r, c});
            
            if (cell[temp.first][temp.second] == "")
            {
                answer.push_back("EMPTY");
            }
            else
            {
                answer.push_back(cell[temp.first][temp.second]);
            }
        }
    }
    
    return answer;
}