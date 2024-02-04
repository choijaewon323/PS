import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    int N;
    int M;
    Map<String, Integer> nameToInt = new HashMap<>();
    Map<Integer, String> intToName = new HashMap<>();

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    boolean isNumber(final String str) {
        final char c = str.charAt(0);

        if ('0' <= c && c <= '9') {
            return true;
        }

        return false;
    }

    void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(reader.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= N; i++) {
            final String name = reader.readLine();

            nameToInt.put(name, i);
            intToName.put(i, name);
        }

        for (int i = 0; i < M; i++) {
            final String input = reader.readLine();

            if (isNumber(input)) {
                final int num = Integer.parseInt(input);
                final String name = intToName.get(num);

                writer.write(name);
            } else {
                final int num = nameToInt.get(input);

                writer.write(String.valueOf(num));
            }
            writer.newLine();
        }

        writer.flush();

        close();
    }


    void close() throws Exception {
        reader.close();
        writer.close();
    }
}