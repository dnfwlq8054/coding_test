import java.lang.*;

public class test1{
    public static void main(String[] args){
        int n = 8;
        String answer = "1";
    
        while(--n != 0){
            StringBuilder temp = new StringBuilder("");
            char c = ' ';

            for(int i = 0; i < answer.length(); i++){
                c = answer.charAt(i);
                int count = 0;

                for(int j = i; j < answer.length(); j++){
                    if( answer.charAt(j) == c ) count++;
                    else break;
                }
                
                i += count - 1;
                temp.append(count + "");
                temp.append(c);
            }
            answer = temp.toString();
        }
        System.out.println(answer);
    }
}
