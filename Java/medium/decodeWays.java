import java.util.*;

class Solution {
    public static int numDecodings(String s) {
        if(s.charAt(0) == '0') return 0;
        if(s.length() == 1) return 1;

        int[] dp = new int[s.length() + 1];
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 1; i < s.length(); i++){
            if(s.charAt(i) == '0'){
                if(s.charAt(i - 1) == '0' || s.charAt(i - 1)  > '2') return 0;
                dp[i + 1] = dp[i - 1];
            }
            else{
                if(s.charAt(i - 1)  > '2'){
                    //   1 1 1 3 1
                    // 1 1 2 3 4 4
                    dp[i + 1] = dp[i];
                }
                else if(s.charAt(i - 1)  == '2' && s.charAt(i)  >'6'){
                    //   1 1 1 2 7
                    // 1 1 2 3 4 4
                    dp[i + 1] = dp[i];
                }
                else if(s.charAt(i - 1) == '0'){
                    //   1 1 1 0 5
                    // 1 1 2 3 2 2
                    dp[i + 1] = dp[i];
                }
                else{
                    //   1 1 1 2 5
                    // 1 1 2 3 5 8
                    dp[i + 1] = dp[i] + dp[i - 1];
                }
            }
        }

        return dp[s.length()];
    }

    // Code = "12"     Ways to decode = 2
    // Code = "27"     Ways to decode = 1
    // Code = "111"    Ways to decode = 3
    // Code = "1000"   Ways to decode = 0
    // Code = "1001"   Ways to decode = 0
    // Code = "111026" Ways to decode = 4
    // Code = "11125"  Ways to decode = 8
    // Code = "2611055971756562"       Ways to decode = 4

    public static void main(String[] args){
        List<String> testSet = new ArrayList<>();
        testSet.add("12");
        testSet.add("27");
        testSet.add("111");
        testSet.add("1000");
        testSet.add("1001");
        testSet.add("111026");
        testSet.add("11125");
        testSet.add("2611055971756562");

        for(String test : testSet){
            System.out.println("Code = \"" + test + "\"\tWays to decode = " + numDecodings(test));
        }
    }
}