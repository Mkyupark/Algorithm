import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int idx = Integer.parseInt(st.nextToken());
		int size = Integer.parseInt(st.nextToken());
		
		int[] arr =  new int [idx +1];
		int[] sumArr = new int [idx + 2];
		
		st = new StringTokenizer(br.readLine());
		sumArr[1] = Integer.parseInt(st.nextToken());
		for(int i =2; i<=idx; i++) {
			sumArr[i] = sumArr[i-1] + Integer.parseInt(st.nextToken());
		}
		for(int i= 0; i < size; i++) {
			st = new StringTokenizer(br.readLine());
			int firstIdx = Integer.parseInt(st.nextToken());
			int secondIdx = Integer.parseInt(st.nextToken());
			int result = sumArr[secondIdx] - sumArr[firstIdx -1];
			System.out.println(result);
		}
		
		
	}
}
