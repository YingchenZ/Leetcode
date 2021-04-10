import java.util.*;

public class uglyNumber{
    public static boolean isUgly(int n) {
        if(n == 1) return true;
        if(n <= 0) return false;
    
        while(n > 0){
            if(n % 2 == 0){
                n /= 2;
            }
            else if (n % 3 == 0){
                n /= 3;
            }
            else if (n % 5 == 0){
                n /= 5;
            }
            else if (n == 1){
                return true;
            }
            else{
                return false;
            }
        }
        return true;
    }

    // Number = 1      => ugly
    // Number = 6      => ugly
    // Number = 8      => ugly
    // Number = -2     => not ugly
    // Number = 21     => not ugly
    // Number = 14     => not ugly
    // Number = 2147483647     => not ugly
    // Number = -2147483648    => not ugly
    
    public static void main(String args[]){
        int testSet[] = {1,6,8,-2,21,14,2147483647,-2147483648};


        for(int test : testSet){
            System.out.println("Number = " + test + "\t=> "+ (isUgly(test)?"":"not ")+ "ugly");
        }
    }
}
