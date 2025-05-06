import java.io.*;
import java.util.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st;
    int N;
    int[] A;
    int[] answer;
    Stack<Pair> stack = new Stack<>();

    public static void main(String[] args) throws IOException {
        new Main().solve();
    }

    public void solve() throws IOException {
        N = Integer.parseInt(reader.readLine());
        answer = new int[N];
        A = new int[N];
        st = new StringTokenizer(reader.readLine(), " ");
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < N; i++) {
            int num = A[i];

            if (stack.isEmpty()) {
                stack.add(new Pair(i, num));
            } else {
                Pair top = stack.peek();

                if (top.num >= num) {
                    stack.add(new Pair(i, num));
                } else {
                    while (!stack.isEmpty() && stack.peek().num < num) {
                        Pair temp = stack.pop();
                        answer[temp.index] = num;
                    }
                    stack.add(new Pair(i, num));
                }
            }
        }

        for (int i = 0; i < N; i++) {
            int num = answer[i];
            if (num == 0) {
                writer.write(String.valueOf(-1));
            } else {
                writer.write(String.valueOf(num));
            }
            writer.write(" ");
        }
        writer.write("\n");

        close();
    }

    static class Pair {
        int index;
        int num;

        public Pair(int index, int num) {
            this.index = index;
            this.num = num;
        }
    }

    public void close() throws IOException {
        reader.close();
        writer.close();
    }
}
