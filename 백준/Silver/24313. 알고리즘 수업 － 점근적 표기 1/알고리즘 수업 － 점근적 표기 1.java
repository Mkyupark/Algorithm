import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int a1 = Integer.parseInt(st.nextToken());
		int a0 = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		int c = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int num = Integer.parseInt(st.nextToken());
		
		if((a1 * num + a0) <= c * num && c>= a1) {
			System.out.println(1);
		}else {
			System.out.println(0);
		}
		
	}
}