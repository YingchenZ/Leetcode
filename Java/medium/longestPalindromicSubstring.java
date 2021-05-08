import java.util.*;

class Solution {
    public static String longestPalindrome(String s) {
        if(s.length() <= 1) return s;
        int start = 0, end = 0;
        for(int i = 0; i < s.length(); i++){
            int[] odd = getPalindrome(s, i, i);
            int[] even = getPalindrome(s, i, i+1);

            if(odd[1] - odd[0] > end - start){
                end = odd[1];
                start = odd[0];
            }
            if(even[1] - even[0] > end - start){
                end = even[1];
                start = even[0];
            }
        }

        return s.substring(start, end + 1);
    }

    public static int[] getPalindrome(String s, int left, int right){
        int[] p = new int[2];

        while(left <= right && left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)){
            left--;
            right++;
        }
        p[0] = left + 1;
        p[1] = right - 1;

        return p;
    }

    // s = a   Longest Palindromic Substring = a
    // s = ac  Longest Palindromic Substring = a
    // s = cbbd        Longest Palindromic Substring = bb 
    // s = babad       Longest Palindromic Substring = bab

    public static void main(String[] args){
        String[] testSet = new String[]{"a", "ac", "cbbd","babad"};
        for(String test : testSet){
            System.out.println("s = " + test + "\tLongest Palindromic Substring = " + longestPalindrome(test));
        }
    
    }
}