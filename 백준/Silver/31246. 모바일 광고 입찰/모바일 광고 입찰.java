import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int lineNum = Integer.parseInt(st.nextToken());
		int bidCnt = Integer.parseInt(st.nextToken());
		
		ArrayList<Integer> inputValues= new ArrayList<>();
		               
		while(lineNum-- > 0) {
			st = new StringTokenizer(br.readLine());
			int moloco = Integer.parseInt(st.nextToken());
			int bidPrize = Integer.parseInt(st.nextToken());
			int diff = bidPrize - moloco;
			if(diff < 0) {
				diff = 0;
			}
			
			inputValues.add(diff);
		}
		
		Collections.sort(inputValues);
		
		System.out.println(inputValues.get(bidCnt - 1));
		
	}
	
}