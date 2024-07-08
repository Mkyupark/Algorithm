import java.util.*;
import java.text.SimpleDateFormat;
import java.text.ParseException;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        List<Integer> answerList = new ArrayList<>();
        // termp 맵 설정
        Map<String, String> termsMap = new HashMap<>();
        String[][] privaciesInfo = new String[privacies.length][];
        
        // terms 분리
        for(String term : terms){
            String[] temp = term.split(" ");
            termsMap.put(temp[0], temp[1]);
        }
       // privacies 분리
        for (int idx = 0; idx < privacies.length; idx++) {
            privaciesInfo[idx] = privacies[idx].split(" ");
        }
        
        // 데이터 포맷 형식을 지정
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy.MM.dd");
        // Calendar 객체 사용하기 위한 인스턴스
        Calendar cal = Calendar.getInstance();
        
        try {
            // 문자열을 Date 객체로 변환
            Date todayDate = simpleDateFormat.parse(today);
            
            // privacies 분리 및 계산
            for(int i = 0; i < privaciesInfo.length; i++){
                Date date = simpleDateFormat.parse(privaciesInfo[i][0]);
                // Date 객체를 Calendar 객체에 설정
                cal.setTime(date);
                String value = termsMap.get(privaciesInfo[i][1]);
                // 원하는 개월 수를 더하기
                cal.add(Calendar.MONTH, Integer.parseInt(value));
                
                // 28일 기준 계산
                cal.add(Calendar.DAY_OF_MONTH, -1);
                
                Date expirationDate = cal.getTime();
                if(expirationDate.before(todayDate)){
                    answerList.add(i + 1);
                }
            }
        } catch (ParseException e) {
            e.printStackTrace();
        }
        

        // ArrayList를 배열로 변환
        int[] answer = answerList.stream().mapToInt(i -> i).toArray();
        return answer;
    }
}
