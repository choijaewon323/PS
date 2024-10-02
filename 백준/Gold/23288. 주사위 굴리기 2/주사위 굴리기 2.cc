#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define UP 0
#define DOWN 1
#define NORTH 2
#define SOUTH 3
#define WEST 4
#define EAST 5

#define DICE_LEFT 0
#define DICE_UP 1
#define DICE_RIGHT 2
#define DICE_DOWN 3

#define CLOCK 0
#define COUNTER 1

#define MAX 20

vector<int> dice(6);
int board[MAX][MAX];
int score[MAX][MAX];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int N, M, K;


void moveLeft() {
    vector<int> nextDice = dice;
    
    nextDice[WEST] = dice[UP];
    nextDice[UP] = dice[EAST];
    nextDice[DOWN] = dice[WEST];
    nextDice[EAST] = dice[DOWN];

    dice = nextDice;
}

void moveRight() {
    vector<int> nextDice = dice;
    
    nextDice[EAST] = dice[UP];
    nextDice[DOWN] = dice[EAST];
    nextDice[UP] = dice[WEST];
    nextDice[WEST] = dice[DOWN];

    dice = nextDice;
}

void moveUp() {
    vector<int> nextDice = dice;
    
    nextDice[NORTH] = dice[UP];
    nextDice[UP] = dice[SOUTH];
    nextDice[DOWN] = dice[NORTH];
    nextDice[SOUTH] = dice[DOWN];

    dice = nextDice;
}

void moveDown() {
    vector<int> nextDice = dice;
    
    nextDice[SOUTH] = dice[UP];
    nextDice[DOWN] = dice[SOUTH];
    nextDice[UP] = dice[NORTH];
    nextDice[NORTH] = dice[DOWN];

    dice = nextDice;
}

void init() {
    dice[UP] = 1;
    dice[NORTH] = 2;
    dice[SOUTH] = 5;
    dice[EAST] = 3;
    dice[WEST] = 4;
    dice[DOWN] = 6; 
}

bool inRange(int y, int x) {
    return (0 <= y && y < N && 0 <= x && x < M);
}

int oppositeDirection(int direction) {
    switch (direction) {
    case DICE_LEFT:
        return DICE_RIGHT;
    case DICE_RIGHT:
        return DICE_LEFT;
    case DICE_UP:
        return DICE_DOWN;
    case DICE_DOWN:
        return DICE_UP;    
    }
    return -1;
}

pair<int, int> nextMove(int y, int x, int direction) {
    int ny = y;
    int nx = x;
    
    switch (direction) {
    case DICE_LEFT:
        nx--;
        moveLeft();
        break;
    case DICE_RIGHT:
        nx++;
        moveRight();
        break;
    case DICE_UP:
        ny--;
        moveUp();
        break;
    case DICE_DOWN:
        ny++;
        moveDown();
        break;
    }

    return {ny, nx};
}

bool canMove(int y, int x, int direction) {
    int ny = y;
    int nx = x;
    
    switch (direction) {
    case DICE_LEFT:
        nx--;
        break;
    case DICE_RIGHT:
        nx++;
        break;
    case DICE_UP:
        ny--;
        break;
    case DICE_DOWN:
        ny++;
        break;
    }

    if (inRange(ny, nx)) {
        return true;
    }
    return false;
}

int getDown() {
    return dice[DOWN];
}

void bfs(int startY, int startX) {
    int presentScore = board[startY][startX];
    int cnt = 1;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;

    visited[startY][startX] = true;
    q.push({startY, startX});
    vector<pair<int, int>> prevPos;
    prevPos.push_back({startY, startX});

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (inRange(ny, nx) &&
                board[ny][nx] == presentScore &&
                !visited[ny][nx]) {
                    cnt++;
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                    prevPos.push_back({ny, nx});
                }
        }
    }

    int result = presentScore * cnt;
    for (pair<int, int>& pos : prevPos) {
        score[pos.first][pos.second] = result;
    }
}

void initScore() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (score[y][x] == 0) {
                bfs(y, x);
            }
        }
    }
}

int rollDirectionClock(int direction) {
    return (direction + 1) % 4;
}

int rollDirectionCounter(int direction) {
    direction--;
    direction %= 4;
    if (direction < 0) {
        direction += 4;
    }
    return direction;
}

void printScore() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cout << score[y][x] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int solve() {
    initScore();
    //printScore();
    int y = 0;
    int x = 0;
    int acc = 0;
    int direction = DICE_RIGHT;

    for (int i = 0; i < K; i++) {
        if (!canMove(y, x, direction)) {
            direction = oppositeDirection(direction);
        }

        pair<int, int> nextPos = nextMove(y, x, direction);
        
        int tempScore = board[nextPos.first][nextPos.second];
        acc += score[nextPos.first][nextPos.second];
        int diceNumber = getDown();

        y = nextPos.first;
        x = nextPos.second;

        if (diceNumber > tempScore) {
            direction = rollDirectionClock(direction);
        } else if (diceNumber < tempScore) {
            direction = rollDirectionCounter(direction);
        }
    }

    return acc;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> board[y][x];
        }
    }

    init();
    cout << solve() << '\n';

    return 0;
}