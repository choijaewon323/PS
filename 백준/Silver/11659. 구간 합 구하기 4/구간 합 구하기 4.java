import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    static final int MAX = 100000;
    int N;
    int M;
    int[] acc = new int[MAX + 1];

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        input();

        close();
    }

    void output() throws Exception {

    }

    void input() throws Exception {
        StringTokenizer st = new StringTokenizer(reader.readLine(), " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(reader.readLine(), " ");
        for (int i = 1; i <= N; i++) {
            final int num = Integer.parseInt(st.nextToken());

            acc[i] = acc[i - 1] + num;
        }

        for (int m = 0; m < M; m++) {
            st = new StringTokenizer(reader.readLine(), " ");
            final int i = Integer.parseInt(st.nextToken());
            final int j = Integer.parseInt(st.nextToken());

            final int answer = acc[j] - acc[i - 1];
            writer.write(String.valueOf(answer));
            writer.newLine();
        }

        writer.flush();
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}