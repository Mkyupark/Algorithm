import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void CalKandMove (int big, int small) {
		int k = (small * 2<  big) ? small + 1 : small;
		long moves;
		if(k == small) {
			moves = 7;
		}else {
			if(k == (big- 1)) moves = 5;
			else if(2*k >= big) moves = 7;
			else {
				moves = (long)(big - 2* k) * 2 + 7;	
			}
		}
		
	    System.out.println(k + " " + moves);
	}
	public static void main(String args[]) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int cnt = Integer.parseInt(st.nextToken());
		while(cnt-- >0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			
			if(n > m) {
				CalKandMove(n, m);
			}else if (n == m) {
				System.out.println(n + " " + 3);
			}else {
				CalKandMove(m, n);
			}			
		}

	}
}