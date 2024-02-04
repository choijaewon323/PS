import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    int N;
    int M;
    char[][] campus;
    boolean[][] visited = new boolean[600][600];
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, -1, 0, 1};

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(reader.readLine(), " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        campus = new char[N][M];

        for (int y = 0; y < N; y++) {
            final String line = reader.readLine();
            for (int x = 0; x < M; x++) {
                campus[y][x] = line.charAt(x);
            }
        }

        final int answer = bfs();

        if (answer == 0) {
            writer.write("TT");
        } else {
            writer.write(String.valueOf(answer));
        }
        writer.newLine();
        writer.flush();

        close();
    }

    int bfs() {
        final Pair start = findStart();
        Queue<Pair> q = new LinkedList<>();
        visited[start.y][start.x] = true;
        q.add(start);

        int result = 0;
        while (!q.isEmpty()) {
            final Pair present = q.poll();

            if (campus[present.y][present.x] == 'P') {
                result++;
            }

            for (int i = 0; i < 4; i++) {
                final int ny = present.y + dy[i];
                final int nx = present.x + dx[i];

                if (inRange(ny, nx) && campus[ny][nx] != 'X' && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.add(new Pair(ny, nx));
                }
            }
        }

        return result;
    }

    boolean inRange(final int y, final int x) {
        if (0 <= y && y < N && 0 <= x && x < M) {
            return true;
        }
        return false;
    }

    Pair findStart() {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (campus[y][x] == 'I') {
                    return new Pair(y, x);
                }
            }
        }

        return new Pair(-1, -1);
    }

    static class Pair {
        int y;
        int x;
        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}