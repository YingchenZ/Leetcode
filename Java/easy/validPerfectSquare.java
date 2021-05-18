import java.util.*;

class Solution {
    public static boolean isPerfectSquare(int num) {
        long left = 0, right = num;
        long mid = 0;
        while(left <= right){
            mid = (left + right) / 2;
            if(mid * mid == num){
                return true;
            }
            else if(mid * mid < num){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return false;
    }

    // 1       Perfect Square
    // 14      Not Perfect Square
    // 15      Not Perfect Square
    // 16      Perfect Square    
    // 20      Not Perfect Square
    // 100     Perfect Square    
    // 2147483647      Not Perfect Square

    public static void main(String[] args){
        int[] testSet = new int[]{1,14,15,16,20,100,2147483647};

        for(int test : testSet){
            System.out.println(test + "\t" + (isPerfectSquare(test)? "Perfect Square" : "Not Perfect Square"));
        }
    }
}