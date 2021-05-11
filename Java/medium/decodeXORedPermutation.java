import java.util.*;

class Solution {
    public static int[] decode(int[] encoded) {
        int[] ans = new int[encoded.length + 1];
        int total = 0;
        int excludeFirst = 0;

        for(int i = 1; i <= encoded.length + 1; i++){
            total ^= i;
        }

        for(int i = 1; i < encoded.length; i+= 2){
            excludeFirst ^= encoded[i];
        }

        ans[0] = total ^ excludeFirst;
        for(int i = 0; i < encoded.length; i++){
            ans[i + 1] = encoded[i] ^ ans[i];
        }
        return ans;
    }

    // encoded = [3, 1]
    // decoded = [1, 2, 3]      
    
    // encoded = [6, 5, 4, 6]   
    // decoded = [2, 4, 1, 5, 3]

    public static void main(String[] args){
        int[][] testSet = new int[][]{{3,1}, {6,5,4,6}};

        for(int[] test : testSet){
            System.out.println("encoded = " + Arrays.toString(test));
            int[] decoded = decode(test);
            System.out.println("decoded = " + Arrays.toString(decoded) + '\n');
        }
    }
}