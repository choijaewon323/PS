import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    int N;
    boolean[][] matrix = new boolean[100][100];

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    public void init() {
        for (int i = 0; i < matrix.length; i++) {
            Arrays.fill(matrix[i], false);
        }
    }

    public void solution() throws Exception {
        init();
        input();

        floydWarshall();
        output();

        close();
    }

    void output() throws IOException {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (!matrix[y][x]) {
                    writer.write("0 ");
                }
                else {
                    writer.write("1 ");
                }
            }
            writer.newLine();
        }
        writer.flush();
    }

    void floydWarshall() {
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (matrix[i][k] && matrix[k][j]) {
                        matrix[i][j] = true;
                    }
                }
            }
        }
    }

    void input() throws Exception {
        N = Integer.valueOf(reader.readLine());

        for (int i = 0; i < N; i++) {
            String line = reader.readLine();

            StringTokenizer tokenizer = new StringTokenizer(line, " ");

            int cnt = 0;
            while (tokenizer.hasMoreTokens()) {
                final int num = Integer.valueOf(tokenizer.nextToken());

                if (num == 1) {
                    matrix[i][cnt] = true;
                }
                else {
                    matrix[i][cnt] = false;
                }
                cnt++;
            }
        }
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}