import java.util.*;

class Solution {
    public static int mySqrt(int x) {
        if(x <= 1)  return x;
        Long left = 1L, right = Long.valueOf(x), mid = 0L;
        Long possibleAns = 0L, square = 0L;

        while(left <= right){
            mid = (left + right) / 2;
            square = mid * mid;
            if(square == x)   return mid.intValue();
            else if(square > x){
                right = mid - 1;
            }
            else{
                possibleAns = Math.max(possibleAns, mid);
                left = mid + 1;
            }
        }
        return possibleAns.intValue();
    }

    // Sqrt(1) = 1
    // Sqrt(3) = 1
    // Sqrt(4) = 2
    // Sqrt(8) = 2
    // Sqrt(17) = 4
    // Sqrt(2147483647) = 46340

    public static void main(String[] args){
        int[] testSet = new int[]{1,3,4,8,17,2147483647};
        for(int test : testSet){
            System.out.println("Sqrt(" + test + ") = " + mySqrt(test));
        }
        
    }
}