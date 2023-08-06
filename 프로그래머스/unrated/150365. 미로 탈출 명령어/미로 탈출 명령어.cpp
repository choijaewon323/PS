#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define DOWN 0
#define LEFT 1
#define RIGHT 2
#define UP 3

int dy[] = {1, 0, 0, -1};
int dx[] = {0, -1, 1, 0};

int N, M;

bool inRange(int y, int x)
{
    if (0 <= y && y < N && 0 <= x && x < M)
    {
        return true;
    }
    return false;
}

int dist(int y, int x, int r, int c)
{
    return abs(y - r) + abs(x - c);
}

string result = "";

bool solve(int y, int x, int r, int c, int k, string str)
{
    if (str.size() == k)
    {
        if (y == r && x == c)
        {
            result += str;
            
            return true;
        }
        return false;
    }
    
    int d = dist(y, x, r, c);
    
    if (k - str.size() < d)
    {
        return false;
    }
    
    if ((k - str.size() - d) % 2 == 1)
    {
        return false;
    }
    
    
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (inRange(ny, nx))
        {
            string temp;
            switch (i)
            {
                case UP:
                    temp += 'u';
                    break;
                case DOWN:
                    temp += 'd';
                    break;
                case LEFT:
                    temp += 'l';
                    break;
                case RIGHT:
                    temp += 'r';
                    break;
            }
            
            bool result = solve(ny, nx, r, c, k, str + temp);
            
            if (result)
            {
                return true;
            }
        }
    }
    
    return false;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    swap(x, y);

    N = n;
    M = m;
    
    bool temp = solve(y-1, x-1, r-1, c-1, k, answer);
    
    if (temp)
    {
        answer = result;
    }
    else
    {
        answer = "impossible";
    }
    
    return answer;
}