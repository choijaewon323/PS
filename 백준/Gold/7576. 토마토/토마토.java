import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    int N;
    int M;
    int[][] tomato;
    int[][] dist;
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, -1, 0, 1};

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(reader.readLine(), " ");
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        tomato = new int[N][M];
        dist = new int[N][M];
        for (int y = 0; y < N; y++) {
            st = new StringTokenizer(reader.readLine(), " ");
            for (int x = 0; x < M; x++) {
                tomato[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        final int answer = bfs();

        writer.write(String.valueOf(answer));
        writer.newLine();
        writer.flush();

        close();
    }

    int bfs() {
        if (isAllReaped()) {
            return 0;
        }
        Queue<Pair> q = new LinkedList<>();
        findReaped(q);

        while (!q.isEmpty()) {
            final Pair present = q.poll();

            for (int i = 0; i < 4; i++) {
                final int ny = present.y + dy[i];
                final int nx = present.x + dx[i];

                if (inRange(ny, nx) && dist[ny][nx] == 0 && tomato[ny][nx] == 0) {
                    dist[ny][nx] = dist[present.y][present.x] + 1;
                    tomato[ny][nx] = 1;
                    q.add(new Pair(ny, nx));
                }
            }
        }

        if (!isAllReaped()) {
            return -1;
        }

        return findAnswer();
    }

    int findAnswer() {
        int result = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (tomato[y][x] == -1) {
                    continue;
                }

                result = Math.max(result, dist[y][x]);
            }
        }
        return result - 1;
    }

    boolean inRange(final int y, final int x) {
        if (0 <= y && y < N && 0 <= x && x < M) {
            return true;
        }
        return false;
    }

    void findReaped(final Queue<Pair> q) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (tomato[y][x] == 1) {
                    q.add(new Pair(y, x));
                    dist[y][x] = 1;
                }
            }
        }
    }

    boolean isAllReaped() {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (tomato[y][x] == -1) {
                    continue;
                }
                if (tomato[y][x] == 0) {
                    return false;
                }
            }
        }

        return true;
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