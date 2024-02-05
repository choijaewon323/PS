import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    Deque<Integer> dq;
    boolean isFlip;

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    void solution() throws Exception {
        final int T = Integer.parseInt(reader.readLine());

        for (int test = 0; test < T; test++) {
            final String p = reader.readLine();
            final int n = Integer.parseInt(reader.readLine());
            final String arrStr = reader.readLine();

            init();

            StringTokenizer st = new StringTokenizer(arrStr.substring(1, arrStr.length() - 1), ",");

            for (int i = 0; i < n; i++) {
                dq.addLast(Integer.parseInt(st.nextToken()));
            }

            if (!solve(p, n)) {
                writer.write("error");
            } else {
                if (isFlip) {
                    final String result = reverseOrder();

                    writer.write(result);
                } else {
                    final String result = inOrder();

                    writer.write(result);
                }
            }
            writer.newLine();
        }

        writer.flush();

        close();
    }

    String inOrder() {
        List<String> strings = new ArrayList<>();
        while (!dq.isEmpty()) {
            strings.add(String.valueOf(dq.removeFirst()));
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        sb.append(String.join(",", strings));
        sb.append("]");

        return sb.toString();
    }

    String reverseOrder() {
        List<String> strings = new ArrayList<>();
        while (!dq.isEmpty()) {
            strings.add(String.valueOf(dq.removeLast()));
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        sb.append(String.join(",", strings));
        sb.append("]");

        return sb.toString();
    }

    boolean solve(final String p, final int n) {
        for (int i = 0; i < p.length(); i++) {
            final char command = p.charAt(i);

            if (command == 'R') {
                if (isFlip) {
                    isFlip = false;
                } else {
                    isFlip = true;
                }
            } else {
                if (dq.isEmpty()) {
                    return false;
                }

                if (isFlip) {
                    dq.removeLast();
                } else {
                    dq.removeFirst();
                }
            }
        }

        return true;
    }

    void init() {
        dq = new LinkedList<>();
        isFlip = false;
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}