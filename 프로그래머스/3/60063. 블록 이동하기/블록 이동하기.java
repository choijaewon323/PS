import java.util.*;

class Solution {
    
    static final int RIGHT = 0;
    static final int UP = 1;
    static final int LEFT = 2;
    static final int DOWN = 3;
    
    static final int INF = 1000000000;
    
    int[][] map;
    int size;
    
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, -1, 0, 1};
    
    public int solution(int[][] board) {
        map = board;
        size = board.length;
        
        int answer = solve(0, 0);
        
        return answer;
    }
    
    int solve(int startY, int startX) {
        Queue<Pair> q = new LinkedList<>();
        
        int[][][] dist = new int[size][size][4];
        
        dist[startY][startX][RIGHT] = 1;
        
        q.add(new Pair(startY, startX, RIGHT));
        
        while (!q.isEmpty()) {
            Pair present = q.poll();
            int y = present.y;
            int x = present.x;
            int direction = present.direction;
            
            if (isEnd(y, x, direction)) {
                return dist[y][x][direction] - 1;
            }
            
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if (canMove(ny, nx, direction) && dist[ny][nx][direction] == 0) {
                    dist[ny][nx][direction] = dist[y][x][direction] + 1;
                    q.add(new Pair(ny, nx, direction));
                }
            }
            
            if (canClockRoll(y, x, direction)) {
                int nextDirect = (direction - 1) % 4;
                if (nextDirect < 0) {
                    nextDirect += 4;
                }

                if (dist[y][x][nextDirect] == 0) {
                    dist[y][x][nextDirect] = dist[y][x][direction] + 1;
                    q.add(new Pair(y, x, nextDirect));
                }
            }

            if (canCounterRoll(y, x, direction)) {
                int nextDirect = (direction + 1) % 4;

                if (dist[y][x][nextDirect] == 0) {
                    dist[y][x][nextDirect] = dist[y][x][direction] + 1;
                    q.add(new Pair(y, x, nextDirect));
                }
            }
            
            Pair rest = getRest(y, x, direction);
        
            if (canClockRoll(rest.y, rest.x, rest.direction)) {
                int nextDirect = (rest.direction - 1) % 4;

                if (nextDirect < 0) {
                    nextDirect += 4;
                }

                if (dist[rest.y][rest.x][nextDirect] == 0) {
                    dist[rest.y][rest.x][nextDirect] = dist[y][x][direction] + 1;
                    q.add(new Pair(rest.y, rest.x, nextDirect));
                }
            }

            if (canCounterRoll(rest.y, rest.x, rest.direction)) {
                int nextDirect = (rest.direction + 1) % 4;

                if (dist[rest.y][rest.x][nextDirect] == 0) {
                    dist[rest.y][rest.x][nextDirect] = dist[y][x][direction] + 1;
                    q.add(new Pair(rest.y, rest.x, nextDirect));
                }
            }
        }
        
        return -1;
    }
    
    Pair getRest(int y, int x, int direction) {
        if (direction == RIGHT) {
            return new Pair(y, x + 1, LEFT);
        }
        
        if (direction == UP) {
            return new Pair(y - 1, x, DOWN);
        }
        
        if (direction == LEFT) {
            return new Pair(y, x - 1, RIGHT);
        }
        
        return new Pair(y + 1, x, UP);
    }
    
    boolean canCounterRoll(int y, int x, int direction) {
        switch (direction) {
            case RIGHT:
                if (inRange(y - 1, x) && inRange(y - 1, x  + 1) && map[y - 1][x] == 0 && map[y - 1][x + 1] == 0) {
                    return true;
                }
                break;
            case DOWN:
                if (inRange(y, x + 1) && inRange(y + 1, x + 1) && map[y][x + 1] == 0 && map[y + 1][x + 1] == 0) {
                    return true;
                }
                break;
            case LEFT:
                if (inRange(y + 1, x) && inRange(y + 1, x - 1) && map[y + 1][x] == 0 && map[y + 1][x - 1] == 0) {
                    return true;
                }
                break;
            case UP:
                if (inRange(y, x - 1) && inRange(y - 1, x - 1) && map[y][x - 1] == 0 && map[y - 1][x - 1] == 0) {
                    return true;
                }
                break;
        }
        
        return false;
    }
    
    boolean canClockRoll(int y, int x, int direction) {
        switch (direction) {
            case RIGHT:
                if (inRange(y + 1, x) && inRange(y + 1, x + 1) && map[y + 1][x] == 0 && map[y + 1][x + 1] == 0) {
                    return true;
                }
                break;
            case DOWN:
                if (inRange(y, x - 1) && inRange(y + 1, x - 1) && map[y][x - 1] == 0 && map[y + 1][x - 1] == 0) {
                    return true;
                } 
                break;
            case LEFT:
                if (inRange(y - 1, x) && inRange(y - 1, x - 1) && map[y - 1][x] == 0 && map[y - 1][x - 1] == 0) {
                    return true;
                }
                break;
            case UP:
                if (inRange(y, x + 1) && inRange(y - 1, x + 1) && map[y][x + 1] == 0 && map[y - 1][x + 1] == 0) {
                    return true;
                }
                break;
        }
        
        return false;
    }
    
    boolean canMove(int ny, int nx, int direction) {
        int restY = -1;
        int restX = -1;
        
        switch (direction) {
            case RIGHT:
                restY = ny;
                restX = nx + 1;
                break;
            case UP:
                restY = ny - 1;
                restX = nx;
                break;
            case LEFT:
                restY = ny;
                restX = nx - 1;
                break;
            case DOWN:
                restY = ny + 1;
                restX = nx;
                break;
        }
        
        if (inRange(ny, nx) && inRange(restY, restX) && map[ny][nx] == 0 && map[restY][restX] == 0) {
            return true;
        }
        
        return false;
    }
    
    boolean isEnd(int y, int x, int direction) {
        switch (direction) {
            case RIGHT:
                if (isNxN(y, x) || isNxN(y, x + 1)) {
                    return true;
                }
                
                break;
            case UP:
                if (isNxN(y, x) || isNxN(y - 1, x)) {
                    return true;
                }
                break;
            case LEFT:
                if (isNxN(y, x) || isNxN(y, x - 1)) {
                    return true;
                }
                break;
            case DOWN:
                if (isNxN(y, x) || isNxN(y + 1, x)) {
                    return true;
                }
                break;
        }
        
        return false;
    }
    
    boolean isNxN(int y, int x) {
        if (y == size - 1 && x == size - 1) {
            return true;
        }
        
        return false;
    }
    
    boolean inRange(int y, int x) {
        if (0 <= y && y < size && 0 <= x && x < size) {
            return true;
        }
        
        return false;
    }
    
    static class Pair {
        int y;
        int x;
        int direction;
        
        Pair(int y, int x, int direction) {
            this.y = y;
            this.x = x;
            this.direction = direction;
        }
    }
}