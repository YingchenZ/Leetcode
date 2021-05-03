import java.util.*;

class Solution {
    public static int reverse(int x) {
        if(x >= 0 && x < 10) return x;
        if(x > Integer.MAX_VALUE || x < Integer.MIN_VALUE)  return 0;
        boolean negative = x < 0;

        x = Math.abs(x);

        double ans = 0;

        while(x > 0){
            ans = (ans * 10 + x % 10);
            x /= 10;
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