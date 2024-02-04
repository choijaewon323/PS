import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    static final int MAX = 1000;
    int N;
    int M;
    int V;
    List<Integer>[] edges = new List[MAX + 1];
    boolean[] visited = new boolean[MAX + 1];
    boolean[] visited2 = new boolean[MAX + 1];
    List<Integer> dfsResult = new ArrayList<>();
    List<Integer> bfsResult = new ArrayList<>();

    void init() {
        for (int i = 1; i <= MAX; i++) {
            edges[i] = new ArrayList<>();
        }
    }

    void sort() {
        for (int i = 1; i <= MAX; i++) {
            Collections.sort(edges[i]);
        }
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        init();
        StringTokenizer st = new StringTokenizer(reader.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        V = Integer.parseInt(st.nextToken());

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(reader.readLine(), " ");
            final int a = Integer.parseInt(st.nextToken());
            final int b = Integer.parseInt(st.nextToken());

            edges[a].add(b);
            edges[b].add(a);
        }
        sort();
        dfs(V);
        bfs(V);

        List<String> dfsOutput = new ArrayList<>();
        List<String> bfsOutput = new ArrayList<>();
        dfsResult.stream().forEach(e -> {
            dfsOutput.add(String.valueOf(e));
        });
        bfsResult.stream().forEach(e -> {
            bfsOutput.add(String.valueOf(e));
        });

        final String dfsStr = String.join(" ", dfsOutput);
        final String bfsStr = String.join(" ", bfsOutput);

        writer.write(dfsStr);
        writer.newLine();
        writer.write(bfsStr);
        writer.newLine();
        writer.flush();

        close();
    }

    void dfs(final int start) {
        visited[start] = true;
        dfsResult.add(start);

        for (final int next : edges[start]) {
            if (!visited[next]) {
                dfs(next);
            }
        }
    }

    void bfs(final int start) {
        Queue<Integer> q = new LinkedList<>();
        visited2[start] = true;
        q.add(start);

        while (!q.isEmpty()) {
            final int present = q.poll();
            bfsResult.add(present);

            for (final int next : edges[present]) {
                if (!visited2[next]) {
                    visited2[next] = true;
                    q.add(next);
                }
            }
        }
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}