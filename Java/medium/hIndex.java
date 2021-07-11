import java.util.*;

class Solution {
    public static int hIndex(int[] citations) {
        int maxS = 0;
        for(int i : citations){
            maxS = Integer.max(i, maxS); 
        }

        int[] freq = new int[maxS + 1];
        for(int i : citations){
            freq[i]++;
        }
        int[] counting = new int[maxS + 1];
        for(int i = 0; i < freq.length; i++){
            counting[i] = freq[i];
            if(i > 0){
                counting[i] += counting[i - 1];
            }
        }
        int totalP = citations.length;
        for(int h = counting.length - 1; h >= 0; h--){
            int atLeastH = totalP - counting[h] + freq[h];
            if(atLeastH >= h)   return h;
        }

        return 0;
    }

    // [1, 3, 1]
    // H-Index = 1
    // [3, 0, 6, 1, 5]
    // H-Index = 3

    public static void main(String[] args){
        int[][] testSet = new int[][]{
            new int[]{1,3,1},
            new int[]{3,0,6,1,5}
        };

        for(int[] test : testSet){
            System.out.println(Arrays.toString(test));
            System.out.println("H-Index = " + hIndex(test));
        }
    }
}