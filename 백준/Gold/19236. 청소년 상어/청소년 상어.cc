#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define UP 0
#define UPLEFT 1
#define LEFT 2
#define DOWNLEFT 3
#define DOWN 4
#define DOWNRIGHT 5
#define RIGHT 6
#define UPRIGHT 7

#define SIZE 4
#define FISH_MAX 16
#define EMPTY 0
#define SHARK -1

bool inRange(int y, int x) {
    return (0 <= y && y < SIZE && 0 <= x && x < SIZE);
}

pair<int, int> next(int y, int x, int direct) {
    switch (direct) {
    case UP:
        y--;
        break;
    case UPLEFT:
        y--;
        x--;
        break;
    case LEFT:
        x--;
        break;
    case DOWNLEFT:
        y++;
        x--;
        break;
    case DOWN:
        y++;
        break;
    case DOWNRIGHT:
        y++;
        x++;
        break;
    case RIGHT:
        x++;
        break;
    case UPRIGHT:
        y--;
        x++;
        break;
    }
    return { y, x };
}

pair<int, int> findFish(int number, vector<vector<int>> &space) {
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            if (space[y][x] == EMPTY ||
                space[y][x] == SHARK) {
                continue;
            }

            if (space[y][x] == number) {
                return { y, x };
            }
        }
    }
    return { -1, -1 };
}

void moveAllFish(vector<vector<int>> &space, vector<int> &fishDirect) {
    for (int number = 1; number <= FISH_MAX; number++) {
        pair<int, int> presentFish = findFish(number, space);

        if (presentFish.first == -1) {
            continue;
        }

        int y = presentFish.first;
        int x = presentFish.second;
        int direct = fishDirect[number];

        for (int i = 0; i < 8; i++) {
            int nextDirect = (direct + i) % 8;

            pair<int, int> nextPos = next(y, x, nextDirect);

            if (inRange(nextPos.first, nextPos.second) &&
                space[nextPos.first][nextPos.second] != SHARK) {

                swap(space[y][x], space[nextPos.first][nextPos.second]);
                fishDirect[number] = nextDirect;
                break;
            }
        }
    }
}

int findAnswer(int sharkY, int sharkX, vector<vector<int>> space, vector<int> fishDirect) {

    // eat fish
    int answer = space[sharkY][sharkX];
    int sharkDirect = fishDirect[space[sharkY][sharkX]];
    space[sharkY][sharkX] = SHARK;

    // move fish
    moveAllFish(space, fishDirect);

    // move shark
    space[sharkY][sharkX] = EMPTY;
    pair<int, int> nextPos = next(sharkY, sharkX, sharkDirect);
    int temp = 0;
    while (true) {
        if (!inRange(nextPos.first, nextPos.second)) {
            break;
        }

        if (space[nextPos.first][nextPos.second] == EMPTY) {
            nextPos = next(nextPos.first, nextPos.second, sharkDirect);
            continue;
        }

        temp = max(temp, findAnswer(nextPos.first, nextPos.second, space, fishDirect));
        nextPos = next(nextPos.first, nextPos.second, sharkDirect);
    }

    return answer + temp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> space(4, vector<int>(4, 0));
    vector<int> fishDirect(FISH_MAX + 1, -1);

    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            int a, b;

            cin >> a >> b;

            space[y][x] = a;
            fishDirect[a] = b - 1;
        }
    }

    int answer = findAnswer(0, 0, space, fishDirect);

    cout << answer << '\n';

    return 0;
}