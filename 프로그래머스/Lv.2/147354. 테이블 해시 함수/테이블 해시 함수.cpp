#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sortIndex;

bool compare(vector<int>& left, vector<int>& right) {
    if (left[sortIndex] == right[sortIndex]) {
        return left[0] > right[0];
    }
    return left[sortIndex] < right[sortIndex];
}

vector<vector<int>> makeSortedData(vector<vector<int>> data) {
    sort(data.begin(), data.end(), compare);
    
    return data;
}

int makeHash(vector<vector<int>> data, int rowBegin, int rowEnd) {
    int result = 0;
    
    for (int i = rowBegin - 1; i <= rowEnd - 1; i++) {
        int si = 0;
        
        for (int node : data[i]) {
            si += node % (i + 1);
        }
        
        result ^= si;
    }
    
    return result;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    sortIndex = col - 1;
    
    vector<vector<int>> sortedData = makeSortedData(data);
    
    answer = makeHash(sortedData, row_begin, row_end);
    
    return answer;
}