import java.util.*;

class Solution {
    ArrayList<Operator> oper;
    Map<String, String> user;
    public String[] solution(String[] record) {
        ArrayList<String> ans = new ArrayList<>();
        oper = new ArrayList<>();
        user = new HashMap<>();
        for(String rec : record){
            String[] slice = rec.split(" ");
            if(slice[0].equals("Change") == false)
            oper.add(new Operator(slice[0], slice[1]));
            if(slice[0].equals("Leave") == false)
                user.put(slice[1], slice[2]);
        }

        String[] answer = new String[oper.size()];
        int idx = 0;
        for(Operator op : oper){
            answer[idx] = (user.get(op.uid)+op.getOperator());
            idx++;
        }


        return answer;
    }
}


class Operator{
    String operator;
    String uid;

    Operator(String operator, String uid){
        this.operator = operator;
        this.uid = uid;
    }

    String getOperator(){
        if(operator.equals("Enter"))
            return "님이 들어왔습니다.";
        else
            return "님이 나갔습니다.";
    }
}
