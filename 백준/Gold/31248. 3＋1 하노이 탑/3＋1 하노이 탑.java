import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static StringBuilder str = new StringBuilder();
	static int cnt;
	
	public static void HanoiTop (int N, char start, char to, char target) {
		if(N == 1) {
			move(start, target);
			return;
		}
		HanoiTop(N-1, start, target, to);
		move(start, target);
		HanoiTop(N-1, to, start, target);
	}
	public static void move(char a, char b) {
		str.append(a).append(" ").append(b).append("\n");
		cnt++;
	}
	
	public static void dHanoiTop (int N, char start, char target, char rest1, char rest2) {
		if(N == 1) {
			move(start, target);
			return;
		}else if (N == 2) {
			move(start, rest1);
			move(start, target);
			move(rest1, target);
			return;
		}
		HanoiTop(N-2, start, rest1, rest2);
		move(start, rest1);
		move(start, target);
		move(rest1, target);
		dHanoiTop(N-2, rest2, target, start, rest1);
		
	}
	public static void main(String args[]) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int lineCnt = Integer.parseInt(st.nextToken());
		
		dHanoiTop(lineCnt, 'A', 'D', 'B', 'C');
		System.out.println(cnt);
		System.out.println(str);
		 
	}
}