import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    PriorityQueue<Integer> pq = new PriorityQueue<Integer>((e1, e2) -> {
        if (Math.abs(e1.intValue()) == Math.abs(e2.intValue())) {
            if (e1 < e2) {
                return -1;
            }
            return 1;
        } else if (Math.abs(e1.intValue()) < Math.abs(e2.intValue())) {
            return -1;
        }
        return 1;
    });
    int N;

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        N = Integer.parseInt(reader.readLine());

        for (int com = 0; com < N; com++) {
            final int x = Integer.parseInt(reader.readLine());

            if (x == 0) {
                if (pq.isEmpty()) {
                    writer.write("0");
                } else {
                    writer.write(String.valueOf(pq.poll()));
                }
                writer.newLine();
            } else {
                pq.add(x);
            }
        }

        writer.flush();

        close();
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}