#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct node {
    string head;
    int number;
    vector<int> index;
};

bool compare(node& a, node& b) {
    if (a.head == b.head) {
        return a.number < b.number;
    }
    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<node> tempFiles;
    
    for (int i = 0; i < files.size(); i++) {
        string present = files[i];
        int index = 0;
        node temp;
        
        // find head
        string head = "";
        while (!('0' <= present[index] && present[index] <= '9')) {
            char c = present[index];
            if ('A' <= c && c <= 'Z') {
                c += 'a' - 'A';
            }
            head += c;
            index++;
        }
        
        
        // find number
        string num = "";
        while (('0' <= present[index] && present[index] <= '9') && index < files[i].size()) {
            num += present[index];
            index++;
        }
        int number = stoi(num);
        
        // find same
        bool flag = true;
        for (node& nod : tempFiles) {
            if (nod.head == head && nod.number == number) {
                flag = false;
                (nod.index).push_back(i);
                break;
            }
        }
        if (flag) {
            temp.head = head;
            temp.number = number;
            (temp.index).push_back(i);
            tempFiles.push_back(temp);
        }
    }
    
    sort(tempFiles.begin(), tempFiles.end(), compare);
    
    for (node& t : tempFiles) {
        for (int idx : t.index) {
            answer.push_back(files[idx]);
        }
    }
    
    return answer;
}