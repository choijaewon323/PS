import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    int[][] paper = new int[200][200];
    int N;
    int white;
    int blue;

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        input();

        solve(N, new Coor(0, 0), new Coor(N, N));

        output();

        close();
    }

    void output() throws Exception {
        writer.write(String.valueOf(white));
        writer.newLine();
        writer.write(String.valueOf(blue));
        writer.newLine();
        writer.flush();
    }

    boolean isAllWhite(final Coor start, final Coor end) {
        for (int y = start.y; y < end.y; y++) {
            for (int x = start.x; x < end.x; x++) {
                if (paper[y][x] != 0) {
                    return false;
                }
            }
        }

        return true;
    }

    boolean isAllBlue(final Coor start, final Coor end) {
        for (int y = start.y; y < end.y; y++) {
            for (int x = start.x; x < end.x; x++) {
                if (paper[y][x] != 1) {
                    return false;
                }
            }
        }

        return true;
    }

    void solve(final int size, final Coor start, final Coor end) {
        if (size == 1) {
            if (paper[start.y][start.x] == 0) {
                white++;
            } else {
                blue++;
            }

            return;
        }

        if (isAllWhite(start, end)) {
            white++;
            return;
        } else if (isAllBlue(start, end)) {
            blue++;
            return;
        }

        for (int y = start.y; y < end.y; y += size / 2) {
            for (int x = start.x; x < end.x; x += size / 2) {
                final int curSize = size / 2;

                if (isAllWhite(new Coor(y, x), new Coor(y + curSize, x + curSize ))) {
                    white++;
                } else if (isAllBlue(new Coor(y, x), new Coor(y + curSize, x + curSize ))) {
                    blue++;
                } else {
                    solve(curSize, new Coor(y, x), new Coor(y + curSize, x + curSize ));
                }
            }
        }
    }

    void input() throws Exception {
        N = Integer.parseInt(reader.readLine());

        for (int y = 0; y < N; y++) {
            StringTokenizer st = new StringTokenizer(reader.readLine(), " ");

            for (int x = 0; x < N; x++) {
                paper[y][x] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static class Coor {
        int y;
        int x;

        Coor(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}