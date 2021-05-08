import java.util.*;

class Solution {
    public static int longestPalindromeSubseq(String s) {
        int len = s.length();
        int[][] dp = new int[len + 1][len+ 1];
        for(int i = 1; i <= len; i++){
            for(int j = 1; j <= len; j++){
                if(s.charAt(i - 1) == s.charAt(len - j)){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[len][len];
    }

    // s = bbbab       Length of the Longest Palindromic Subsequence = 4

    // s = cbbd        Length of the Longest Palindromic Subsequence = 2

    // s = agbdba      Length of the Longest Palindromic Subsequence = 5

    public static void main(String[] args){
        String[] testSet = new String[]{"bbbab","cbbd","agbdba"};

        for(String test : testSet){
            System.out.println("s = " + test + "\tLength of the Longest Palindromic Subsequence = " + longestPalindromeSubseq(test) +'\n');
        }
    }
}