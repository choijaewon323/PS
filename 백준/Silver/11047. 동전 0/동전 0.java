import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    int N;
    int K;
    int[] coin;

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(reader.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        coin = new int[N];
        for (int i = 0; i < N; i++) {
            coin[i] = Integer.parseInt(reader.readLine());
        }

        int answer = 0;
        for (int i = N - 1; i >= 0; i--) {
            final int present = coin[i];

            if (K >= present) {
                answer += K / present;
                K = K % present;
            }
        }

        writer.write(String.valueOf(answer));
        writer.newLine();

        writer.flush();

        close();
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}