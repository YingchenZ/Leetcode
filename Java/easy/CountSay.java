import java.time.format.TextStyle;
import java.util.*;

public class CountSay {
    public static String countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";

        String before = countAndSay(n - 1);
        int current = 0;
        int count = 1;
        String answer = new String();
  
        for(int i = 1; i < before.length(); i++){
            
            if(!before.substring(i,i+1).equals(before.substring(current,current+1))){
                answer += Integer.toString(count) + before.charAt(current);
                current = i;
                count = 1;
            }
            else{
                count++;
            }
        }
        
        return answer +  Integer.toString(count) + before.charAt(current);
    }
    // N = 1 say 1
    // N = 5 say 111221    
    // N = 8 say 1113213211
    public static void main(String args[]){
        int testSet[] = {1,5,8};

        for(int test : testSet){
            String answer = countAndSay(test);
            System.out.println("N = " + test + " say " + answer);
        }
    }
}