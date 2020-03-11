import java.util.*;

class Solution {
    
    public String solution(int[] numbers) {
        String answer = "";
        
        ArrayList<String> strings = new ArrayList<>();
        
        for(int number : numbers){
            strings.add(Integer.toString(number));
        }
        
        Collections.sort(strings, new Comparator<String>(){
            @Override
            public int compare(String a, String b) {
                return (b+a).compareTo(a+b);
            }
        });
        
        for(String string : strings){
            answer += string;
        }
        
        if(answer.charAt(0) == '0')
            return "0";
        
        return answer;
    }
}
