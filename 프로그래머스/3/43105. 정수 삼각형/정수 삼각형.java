import java.util.*;

class Solution {
    static final int MAX = 500;
    int[][] dp;
    int[][] values;

    public int solution(int[][] triangle) {
        int answer = 0;

        dp = makeDP(triangle.length);
        values = triangle;

        answer = solve(0, 0);

        return answer;
    }

    int[][] makeDP(final int length) {
        int[][] results = new int[length][length];

        for (int y = 0; y < length; y++) {
            for (int x = 0; x < length; x++) {
                results[y][x] = -1;
            }
        }

        return results;
    }

    int solve(int height, int index) {
        if (height == values.length - 1) {
            return values[height][index];
        }

        if (dp[height][index] != -1) {
            return dp[height][index];
        }

        int present = values[height][index];

        dp[height][index] = Math.max(solve(height + 1, index), solve(height + 1, index + 1)) + present;

        return dp[height][index];
    }
}