import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    long[] P = new long[101];

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void calculate() {
        P[1] = 1L;
        P[2] = 1L;
        P[3] = 1L;
        P[4] = 2L;
        P[5] = 2L;
        for (int i = 6; i <= 100; i++) {
            P[i] = P[i - 1] + P[i - 5];
        }
    }

    void solution() throws Exception {
        calculate();

        final int T = Integer.parseInt(reader.readLine());

        for (int test = 0; test < T; test++) {
            final int N = Integer.parseInt(reader.readLine());

            writer.write(String.valueOf(P[N]));
            writer.newLine();
        }

        writer.flush();

        close();
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}