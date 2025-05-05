import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st;
    int N;

    public static void main(String[] args) throws IOException {
        new Main().solve();
    }

    public void solve() throws IOException {
        N = Integer.parseInt(reader.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<>((c1, c2) -> {
            if (c1 < c2) {
                return 1;
            }
            return -1;
        });

        for (int y = 0; y < N; y++) {
            st = new StringTokenizer(reader.readLine(), " ");
            for (int x = 0; x < N; x++) {
                int num = Integer.parseInt(st.nextToken());
                pq.add(num);
            }
        }

        for (int i = 0; i < N - 1; i++) {
            pq.poll();
        }

        writer.write(String.valueOf(pq.poll()));
        writer.flush();

        close();
    }

    public void close() throws IOException {
        reader.close();
        writer.close();
    }
}
