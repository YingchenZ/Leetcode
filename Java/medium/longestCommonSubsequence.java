import java.util.*;

class Solution {
    public static int longestCommonSubsequence(String text1, String text2) {
        int row = text1.length(), col = text2.length();
        int[][] dp = new int[row + 1][col + 1];
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                if(text1.charAt(i - 1) == text2.charAt(j - 1)){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[row][col];
    }

    // text1 = abcde   text2 = ace     Length of the longest common subsequence = 3
    // text1 = abc     text2 = abc     Length of the longest common subsequence = 3
    // text1 = abc     text2 = de      Length of the longest common subsequence = 0
    // text1 = bsbininm        text2 = jmjkbkjkv       Length of the longest common subsequence = 1

    public static void main(String[] args){
        List<String[]> testSet = Arrays.asList(
            new String[]{"abcde","ace"},
            new String[]{"abc","abc"},
            new String[]{"abc", "de"},
            new String[]{"bsbininm", "jmjkbkjkv"}
        );

        for(String[] test : testSet){
            System.out.println( "text1 = " + test[0] + "\ttext2 = " + test[1] + "\tLength of the longest common subsequence = " + longestCommonSubsequence(test[0],test[1]));
        }
    }
}