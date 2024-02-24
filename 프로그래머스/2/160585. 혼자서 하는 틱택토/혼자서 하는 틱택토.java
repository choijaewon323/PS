import java.util.*;

class Solution {
    
    List<char[][]> snapshot = new ArrayList<>();
    char[][] board = new char[3][3];
    
    public int solution(String[] b) {
        init();
        
        if (isSame(board, b)) {
            return 1;   
        }
        
        play('O');
        
        for (final char[][] temp : snapshot) {
            if (isSame(temp, b)) {
                return 1;
            }
        }
        
        return 0;
    }
    
    void init() {
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                board[y][x] = '.';
            }
        }
    }
    
    void play(final char present) {
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                if (board[y][x] == '.') {
                    board[y][x] = present;
                    
                    snapshot.add(copy());
                    
                    if (isEnd()) {
                        board[y][x] = '.';
                        continue;
                    }
                    
                    char next;
                    
                    if (present == 'O') {
                        next = 'X';
                    } else {
                        next = 'O';
                    }
                    
                    play(next);
                    board[y][x] = '.';
                }
            }
        }
    }
    
    char[][] copy() {
        char[][] result = new char[3][3];
        
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                result[y][x] = board[y][x];
            }
        }
        
        return result;
    }
    
    boolean isEnd() {
        for (int y = 0; y < 3; y++) {
            if (checkRow(y)) {
                return true;
            }
        }
        
        for (int x = 0; x < 3; x++) {
            if (checkColumn(x)) {
                return true;
            }
        }
        
        final char middle = board[1][1];
        
        if (middle != '.' && middle == board[0][0] && middle == board[2][2]) {
            return true;
        }
        
        if (middle != '.' && middle == board[0][2] && middle == board[2][0]) {
            return true;
        }
        
        return false;
    }
    
    boolean checkColumn(final int x) {
        final char first = board[0][x];
        
        if (first == '.') {
            return false;
        }
        
        for (int y = 0; y < 3; y++) {
            if (first != board[y][x]) {
                return false;
            }
        }
        
        return true;
    }
    
    boolean checkRow(final int y) {
        final char first = board[y][0];
        
        if (first == '.') {
            return false;
        }
        
        for (int x = 0; x < 3; x++) {
            if (first != board[y][x]) {
                return false;
            }
        }
        
        return true;
    }
    
    boolean isSame(final char[][] com, final String[] b) {
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                final char c = b[y].charAt(x);
                
                if (com[y][x] != c) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
}