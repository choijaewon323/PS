import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    static final int MAX = 50;

    int[][] radish = new int[MAX][MAX];
    boolean[][] visited = new boolean[MAX][MAX];
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, -1, 0, 1};
    int N;
    int M;
    int K;

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        input();

        close();
    }

    void output(final int answer) throws Exception {
        writer.write(String.valueOf(answer));
        writer.newLine();
        writer.flush();
    }

    void init() {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                radish[y][x] = 0;
                visited[y][x] = false;
            }
        }
    }

    static class Pair {
        final int y;
        final int x;

        Pair(final int y, final int x) {
            this.y = y;
            this.x = x;
        }
    }

    boolean inRange(final int y, final int x) {
        if (0 <= y && y < N && 0 <= x && x < M) {
            return true;
        }
        return false;
    }

    void bfs(final int startY, final int startX) {
        visited[startY][startX] = true;
        Queue<Pair> q = new LinkedList<>();

        q.add(new Pair(startY, startX));

        while (!q.isEmpty()) {
            Pair present = q.poll();

            for (int i = 0; i < 4; i++) {
                final int ny = present.y + dy[i];
                final int nx = present.x + dx[i];

                if (inRange(ny, nx) && radish[ny][nx] == 1 && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.add(new Pair(ny, nx));
                }
            }
        }
    }

    int solve() {
        int answer = 0;

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (!visited[y][x] && radish[y][x] == 1) {
                    answer++;
                    bfs(y, x);
                }
            }
        }

        return answer;
    }

    void input() throws Exception {
        final int T = Integer.parseInt(reader.readLine());

        for (int test = 0; test < T; test++) {
            StringTokenizer st = new StringTokenizer(reader.readLine(), " ");

            M = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            init();

            for (int i = 0; i < K; i++) {
                st = new StringTokenizer(reader.readLine(), " ");
                final int x = Integer.parseInt(st.nextToken());
                final int y = Integer.parseInt(st.nextToken());

                radish[y][x] = 1;
            }

            final int answer = solve();
            output(answer);
        }
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}