import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    int M;
    boolean[] numbers = new boolean[21];

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        input();
        close();
    }

    void input() throws Exception {
        M = Integer.parseInt(reader.readLine());

        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(reader.readLine(), " ");

            final String cmd = st.nextToken();

            if (cmd.equals("add")) {
                final int num = Integer.parseInt(st.nextToken());
                numbers[num] = true;
            } else if (cmd.equals("remove")) {
                final int num = Integer.parseInt(st.nextToken());
                numbers[num] = false;
            } else if (cmd.equals("check")) {
                final int num = Integer.parseInt(st.nextToken());
                if (numbers[num]) {
                    writer.write("1\n");
                } else {
                    writer.write("0\n");
                }
            } else if (cmd.equals("toggle")) {
                final int num = Integer.parseInt(st.nextToken());
                if (numbers[num]) {
                    numbers[num] = false;
                } else {
                    numbers[num] = true;
                }
            } else if (cmd.equals("all")) {
                for (int temp = 1; temp <= 20; temp++) {
                    numbers[temp] = true;
                }
            } else if (cmd.equals("empty")) {
                for (int temp = 1; temp <= 20; temp++) {
                    numbers[temp] = false;
                }
            }
        }

        writer.flush();
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}