import java.util.*;
import java.io.*;

public class Main {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    int N;
    int M;
    String S;

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    int[] makePi(final String toFind) {
        final int m = toFind.length();

        final int[] pi = new int[m];
        Arrays.fill(pi, 0);

        int start = 1;
        int matched = 0;
        while (start + matched < m) {
            if (toFind.charAt(start + matched) == toFind.charAt(matched)) {
                matched++;
                pi[start + matched - 1] = matched;
            } else {
                if (matched == 0) {
                    start++;
                } else {
                    start += matched - pi[matched - 1];
                    matched = pi[matched - 1];
                }
            }
        }

        return pi;
    }

    List<Integer> kmp(final String longText, final String toFind) {
        final List<Integer> results = new ArrayList<>();

        final int n = longText.length();
        final int m = toFind.length();
        final int[] pi = makePi(toFind);

        int start = 0;
        int matched = 0;

        while (start <= n - m) {
            if (matched < m && longText.charAt(start + matched) == toFind.charAt(matched)) {
                matched++;

                if (matched == m) {
                    results.add(start);
                }
            } else {
                if (matched == 0) {
                    start++;
                } else {
                    start += matched - pi[matched - 1];
                    matched = pi[matched - 1];
                }
            }
        }

        return results;
    }

    String makePn(final int N) {
        final StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 2 * N + 1; i++) {
            if (i % 2 == 0) {
                sb.append('I');
            } else {
                sb.append('O');
            }
        }

        return sb.toString();
    }

    void solution() throws Exception {
        N = Integer.parseInt(reader.readLine());
        M = Integer.parseInt(reader.readLine());
        S = reader.readLine();
        final String pn = makePn(N);

        List<Integer> answers = kmp(S, pn);

        writer.write(String.valueOf(answers.size()));
        writer.newLine();

        writer.flush();

        close();
    }

    void close() throws Exception {
        reader.close();
        writer.close();
    }
}