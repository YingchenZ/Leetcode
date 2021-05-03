import java.util.*;

class Solution {
    public static int reverse(int x) {
        if(x >= 0 && x < 10) return x;
        boolean negative = x < 0;
        x = Math.abs(x);
        int length = (x+"").length();
        if(length > 10) return 0;
        double ans = 0;

        double len = Math.pow(10, length - 1);
        for(double i = len, j = 1; i > 0 && j <= len; i /= 10, j *= 10){
            ans += ((int)(x / i) * j);
            x -= (int)(x / i) * i;
        }
        ans = (negative? -ans : ans);
        if(ans > Integer.MAX_VALUE || ans < Integer.MIN_VALUE)  return 0;
        return (int)ans;
    }
    
    // Original = 0    => 0
    // Original = 120  => 21       
    // Original = 123  => 321      
    // Original = -123 => -321     
    // Original = 1534236469   => 0

    public static void main(String[] args){
        int[] testSet = new int[]{0, 120, 123, -123, 1534236469};

        for(int test : testSet){
            System.out.println("Original = " + test + "\t=> " + reverse(test));
        }
    }
}