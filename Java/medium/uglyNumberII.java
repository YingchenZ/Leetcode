import java.util.*;

class Solution {
    public static int nthUglyNumber(int n) {
        int[] mem = new int[1690];

        mem[0] = 1;

        int two = 0, three = 0, five = 0;

        for(int i = 1; i < 1690; i++){
            mem[i] = Math.min(Math.min(mem[two] * 2, mem[three] * 3), mem[five] * 5);

            if(mem[i] == mem[two] * 2) two++;
            if(mem[i] == mem[three] * 3) three++;
            if(mem[i] == mem[five] * 5) five++;

            if(i == n - 1) return mem[i];
        }
  
        return mem[n - 1];    
    }

    // The 15th ugly number = 24
    // The 25th ugly number = 54 
    // The 35th ugly number = 108

    public static void main(String[] args){
        int[] testSet = new int[]{15, 25, 35};

        for(int test : testSet){
            System.out.println("The " + test + "th ugly number = " + nthUglyNumber(test));
        }
    }
}