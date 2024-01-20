import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer tokenizer;
    int N;
    int K;
    int[] W = new int[100];
    int[] V = new int[100];
    int[][] dp = new int[100][100000 + 1];

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        input();

        init();

        final int answer = solve(0, K);

        output(answer);

        close();
    }

    void output(final int answer) throws IOException {
        writer.write(String.valueOf(answer));
        writer.newLine();

        writer.flush();
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }

    void init() {
        for (int i = 0; i < 100; i++) {
            Arrays.fill(dp[i], -1);
        }
    }

    int solve(final int index, final int weight) {
        if (index == N) {
            return 0;
        }

        if (dp[index][weight] != -1) {
            return dp[index][weight];
        }

        int result = -1;

        if (weight - W[index] >= 0) {
            // pack
            result = Math.max(result, solve(index + 1, weight - W[index]) + V[index]);
        }

        // unpack
        result = Math.max(result, solve(index + 1, weight));

        return dp[index][weight] = result;
    }

    void input() throws Exception {
        String first = reader.readLine();

        tokenizer = new StringTokenizer(first);
        N = Integer.parseInt(tokenizer.nextToken());
        K = Integer.parseInt(tokenizer.nextToken());

        for (int i = 0; i < N; i++) {
            String temp = reader.readLine();

            tokenizer = new StringTokenizer(temp);
            W[i] = Integer.parseInt(tokenizer.nextToken());
            V[i] = Integer.parseInt(tokenizer.nextToken());
        }
    }
}