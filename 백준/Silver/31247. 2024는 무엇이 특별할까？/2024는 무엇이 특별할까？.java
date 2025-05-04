import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int lineNum = Integer.parseInt(st.nextToken());

        while (lineNum-- > 0) {
            st = new StringTokenizer(br.readLine());
            long first = Long.parseLong(st.nextToken());
            long second = Long.parseLong(st.nextToken());
            System.out.println(resultCount(first, second));
        }
    }

    public static long resultCount(long first, long second) {
        if (second >= 63) return 0;
        if (first < (1L << second)) return 0;

        long powK = 1L << second;
        long powKPlus1 = powK << 1;

        return (first / powK) - (first / powKPlus1);
    }
}