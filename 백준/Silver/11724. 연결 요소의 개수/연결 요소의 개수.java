import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    static final int MAX = 1000;

    int N;
    int M;
    List<Integer>[] edges = new List[MAX + 1];
    boolean[] visited = new boolean[MAX + 1];

    void init() {
        for (int i = 1; i <= MAX; i++) {
            edges[i] = new ArrayList<>();
        }
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void input() throws Exception {
        StringTokenizer st = new StringTokenizer(reader.readLine(), " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(reader.readLine(), " ");

            final int u = Integer.parseInt(st.nextToken());
            final int v = Integer.parseInt(st.nextToken());

            edges[u].add(v);
            edges[v].add(u);
        }
    }

    void solution() throws Exception {
        init();
        input();
        final int answer = solve();
        writer.write(String.valueOf(answer));
        writer.newLine();
        writer.flush();
        close();
    }

    int solve() {
        int result = 0;

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                result++;
                dfs(i);
            }
        }

        return result;
    }

    void dfs(final int start) {
        visited[start] = true;

        for (final int next : edges[start]) {
            if (!visited[next]) {
                dfs(next);
            }
        }
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}