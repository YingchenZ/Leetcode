import java.util.*;



class Solution {
    private static class TestHolder{
        public int[] bloomDay;
        public int m;
        public int k;
        public TestHolder(int[] day, int m, int k){
            this.bloomDay = day;
            this.m = m;
            this.k = k;
        }
    }
    public static int minDays(int[] bloomDay, int m, int k) {
        if(m > (bloomDay.length  / k))  return -1;

        int low = 1000000000, high = 1;
        for(int day : bloomDay){
            low = Math.min(day, low);
            high = Math.max(day, high);
        }
        while(low <= high){
            int mid = (low + high) / 2;
            if(canBloom(bloomDay, m, mid, k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }

    public static boolean canBloom(int[] bloomDay, int demand, int day, int size){
        int flowerCount = 0;
        int bouquet = 0;

        for(int current : bloomDay){
            if(current > day){
                flowerCount = 0;
                continue;
            }
            flowerCount++;
            if(flowerCount == size){
                bouquet++;
                flowerCount = 0;
                if(bouquet == demand) return true;
            }
        }
        return false;
    }

    // bloomDay = [1, 10, 3, 10, 2]    m = 3   k = 1
    // The Minimum Number of Days = 3

    // bloomDay = [1, 10, 3, 10, 2]    m = 3   k = 2
    // The Minimum Number of Days = -1

    // bloomDay = [7, 7, 7, 7, 12, 7, 7]       m = 2   k = 3        
    // The Minimum Number of Days = 12

    // bloomDay = [1000000000, 1000000000]     m = 1   k = 1        
    // The Minimum Number of Days = 1000000000

    // bloomDay = [1, 10, 2, 9, 3, 8, 4, 7, 5, 6]      m = 4   k = 2
    // The Minimum Number of Days = 9

    public static void main(String[] args){
        TestHolder[] testSet = new TestHolder[]{
            new TestHolder(new int[]{1,10,3,10,2},3,1),
            new TestHolder(new int[]{1,10,3,10,2},3,2),
            new TestHolder(new int[]{7,7,7,7,12,7,7},2,3),
            new TestHolder(new int[]{1000000000,1000000000},1,1),
            new TestHolder(new int[]{1,10,2,9,3,8,4,7,5,6},4,2)
        };

        for(TestHolder test : testSet){
            System.out.println("bloomDay = " + Arrays.toString(test.bloomDay) + "\tm = " + test.m + "\tk = " + test.k);
            System.out.println("The Minimum Number of Days = " + minDays(test.bloomDay, test.m, test.k) + '\n');
        }
    }
}