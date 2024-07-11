import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
class Main {
    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            // 입력 시작
            String line = reader.readLine();
            int idx = Integer.parseInt(line);
            String dasomStr = reader.readLine();

            if(idx != 1) {
                int dasom = Integer.parseInt(dasomStr); // 다솜이 득표 수 
                ArrayList<Integer> arr = new ArrayList<>(); // 나머지 사람들
                int answer = 0; // 정답
            
                for(int i = 0; i < idx -1; i++){
                    String temp = reader.readLine();
                    int k = Integer.parseInt(temp);
                    arr.add(k);
                }
                // 입력 끝
                
                // 풀이과정
                // for(int i =0; i< arr.size(); i++){
                //     System.out.println(arr.get(i));
                // }
                while(true){
                    Collections.sort(arr, Collections.reverseOrder()); // 크기 순 정렬
                    // 다솜이가 최대값보다 작은 경우
                    if(dasom <= arr.get(0)){
                        dasom++;
                        arr.set(0, arr.get(0) -1);
                        //System.out.println(arr.get(0));
                        answer++;
                    }else{
                        System.out.println(answer);
                        break;
                    }
                }
            }else{
                System.out.println(0);
            }
            
            
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
