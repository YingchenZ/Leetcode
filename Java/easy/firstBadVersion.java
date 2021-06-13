import java.util.*;

class Solution{
    private static int bad = 0;
    private static boolean isBadVersion(int num){
        return num >= bad;
    }
    public static int firstBadVersion(int n) {
        long left = 0L, right = n;
        while(left <= right){
            long mid = (left + right) / 2;
            if(isBadVersion((int)mid) == true){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return (int)left;
    }
    
    // n = 5   First Bad Version = 4
    // n = 1   First Bad Version = 1
    // n = 18  First Bad Version = 6
    // n = 1705930310  First Bad Version = 1508243771

    public static void main(String[] args){
        int[][] testSet = new int[][]{
            new int[]{5,4},
            new int[]{1,1},
            new int[]{18,6}, 
            new int[]{1705930310,1508243771}
        };

        for(int[] test : testSet){
            bad = test[1];
            System.out.println("n = " + test[0] + "\tFirst Bad Version = " + firstBadVersion(test[0]));
        }
    }
}