#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

#define BLUE_Y 4
#define BLUE_X 6
#define GREEN_Y 6
#define GREEN_X 4

int N;
vector<vector<bool>> blue;
vector<vector<bool>> green;

pair<int, int> limitBlue(int startY, int startX) {
    for (int x = 0; x < BLUE_X; x++) {
        if (blue[startY][x]) {
            return {startY, x - 1};
        }
    }
    return {startY, BLUE_X - 1};
}

pair<int, int> limitGreen(int startY, int startX) {
    for (int y = 0; y < GREEN_Y; y++) {
        if (green[y][startX]) {
            return {y - 1, startX};
        }
    }
    return {GREEN_Y - 1, startX};
}

void putTile(int t, int y, int x) {
    if (t == 1) {
        pair<int, int> nextBlue = limitBlue(y, x);
        pair<int, int> nextGreen = limitGreen(y, x);

        blue[y][nextBlue.second] = true;
        green[nextGreen.first][x] = true;
    } else if (t == 2) {
        // blue
        pair<int, int> rightBlue = limitBlue(y, x + 1);
        blue[y][rightBlue.second] = true;
        blue[y][rightBlue.second - 1] = true;

        // green
        pair<int, int> leftGreen = limitGreen(y, x);
        pair<int, int> rightGreen = limitGreen(y, x + 1);

        int minY = min(leftGreen.first, rightGreen.first);
        green[minY][x] = true;
        green[minY][x + 1] = true;
    } else {
        // blue
        pair<int, int> upBlue = limitBlue(y, x);
        pair<int, int> downBlue = limitBlue(y + 1, x);
        int minX = min(upBlue.second, downBlue.second);
        blue[y][minX] = true;
        blue[y + 1][minX] = true;

        // green
        pair<int, int> downGreen = limitGreen(y + 1, x);
        green[downGreen.first][x] = true;
        green[downGreen.first - 1][x] = true;
    }
}

bool isBlueFull(int x) {
    for (int y = 0; y < BLUE_Y; y++) {
        if (!blue[y][x]) {
            return false;
        }
    }
    return true;
}

int removeBlue() {
    int cnt = 0;
    for (int x = BLUE_X - 1; x >= 0; x--) {
        if (isBlueFull(x)) {
            cnt++;
            for (int y = 0; y < BLUE_Y; y++) {
                blue[y][x] = false;
            }
        }
    }
    return cnt;
}

bool isGreenFull(int y) {
    for (int x = 0; x < GREEN_X; x++) {
        if (!green[y][x]) {
            return false;
        }
    }
    return true;
}

int removeGreen() {
    int cnt = 0;
    for (int y = GREEN_Y - 1; y >= 0; y--) {
        if (isGreenFull(y)) {
            cnt++;
            for (int x = 0; x < GREEN_X; x++) {
                green[y][x] = false;
            }
        }
    }
    return cnt;
}

bool isBlueEmpty(int x) {
    for (int y = 0; y < BLUE_Y; y++) {
        if (blue[y][x]) {
            return false;
        }
    }
    return true;
}

void moveBlue() {
    vector<vector<bool>> nextBlue(BLUE_Y, vector<bool>(BLUE_X, false));
    int index = BLUE_X - 1;

    for (int x = BLUE_X - 1; x >= 0; x--) {
        if (isBlueEmpty(x)) {
            continue;
        }
        
        for (int y = 0; y < BLUE_Y; y++) {
            nextBlue[y][index] = blue[y][x];
        }
        index--;
    }

    blue = nextBlue;
}

bool isGreenEmpty(int y) {
    for (int x = 0; x < GREEN_X; x++) {
        if (green[y][x]) {
            return false;
        }
    }
    return true;
} 

void moveGreen() {
    vector<vector<bool>> nextGreen(GREEN_Y, vector<bool>(GREEN_X, false));
    int index = GREEN_Y - 1;

    for (int y = GREEN_Y - 1; y >= 0; y--) {
        if (isGreenEmpty(y)) {
            continue;
        }
        
        for (int x = 0; x < GREEN_X; x++) {
            nextGreen[index][x] = green[y][x];
        }
        index--;
    }

    green = nextGreen;
}

void specialBlue() {
    int cnt = 0;
    for (int x = 0; x <= 1; x++) {
        for (int y = 0; y < BLUE_Y; y++) {
            if (blue[y][x]) {
                cnt++;
                break;
            }
        }
    }

    for (int x = BLUE_X - 1; x >= BLUE_X - cnt; x--) {
        for (int y = 0; y < BLUE_Y; y++) {
            blue[y][x] = false;
        }
    }
}

void specialGreen() {
    int cnt = 0;
    for (int y = 0; y <= 1; y++) {
        for (int x = 0; x < GREEN_X; x++) {
            if (green[y][x]) {
                cnt++;
                break;
            }
        }
    }

    for (int y = GREEN_Y - 1; y >= GREEN_Y - cnt; y--) {
        for (int x = 0; x < GREEN_X; x++) {
            green[y][x] = false;
        }
    }
}

int solve(int t, int y, int x) {
    putTile(t, y, x);

    int score = removeBlue();
    score += removeGreen();
    moveBlue();
    moveGreen();
    specialBlue();
    specialGreen();
    moveBlue();
    moveGreen();
    return score;
}

int countBlue() {
    int result = 0;
    
    for (int y = 0; y < BLUE_Y; y++) {
        for (int x = 0; x < BLUE_X; x++) {
            if (blue[y][x]) {
                result++;
            }
        }
    }
    return result;
}

int countGreen() {
    int result = 0;
    
    for (int y = 0; y < GREEN_Y; y++) {
        for (int x = 0; x < GREEN_X; x++) {
            if (green[y][x]) {
                result++;
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    blue = vector<vector<bool>>(BLUE_Y, vector<bool>(BLUE_X, false));
    green = vector<vector<bool>>(GREEN_Y, vector<bool>(GREEN_X, false));

    cin >> N;

    int score = 0;
    for (int i = 0; i < N; i++) {
        int t, y, x;

        cin >> t >> y >> x;
        score += solve(t, y, x);
    }
    
    cout << score << '\n';
    cout << countBlue() + countGreen() << '\n';

    return 0;
}