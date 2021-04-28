import java.util.*;

class Solution {
    public static boolean judgeSquareSum(int c) {
        if(c <= 1)  return true;
        for(double a = 0; a * a < c; a++){
            double b = Math.sqrt(c - a * a);
            if((int) b == b) return true;
        }
        return false;
    }

    // Number = 1 is the sum of square numbers.
    // Number = 2 is the sum of square numbers.
    // Number = 3 is not the sum of square numbers.       
    // Number = 4 is the sum of square numbers.
    // Number = 5 is the sum of square numbers.
    // Number = 21473647 is not the sum of square numbers.

    public static void main(String[] args){
        int[] testSet = {1,2,3,4,5,21473647};

        for(int test : testSet){
            System.out.println("Number = " + test + " is " + (judgeSquareSum(test)? "":"not ") + "the sum of square numbers.");
        }
    }
}