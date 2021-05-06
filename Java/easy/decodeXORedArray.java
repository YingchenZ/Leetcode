import java.util.*;

class Solution {
    private static class TestHolder{
        public int[] encoded;
        public int first = -1;
        public TestHolder(int[] encoded, int first){
            this.encoded = encoded;
            this.first = first;
        }
    };

    public static int[] decode(int[] encoded, int first) {
        int[] ans = new int[encoded.length + 1];
        ans[0] = first;
        for(int i = 1; i < ans.length; i++){
            ans[i] = ans[i - 1] ^ encoded[i - 1];
        }
        return ans;
    }
    
    // encoded = [1, 2, 3]     first = 1
    // Original Array = [1, 0, 2, 1]    
    
    // encoded = [6, 2, 7, 3]  first = 4
    // Original Array = [4, 2, 0, 7, 4]

    public static void main(String[] args){
        TestHolder[] testSet = new TestHolder[]{
            new TestHolder(new int[]{1,2,3}, 1),
            new TestHolder(new int[]{6,2,7,3},4)
        };
        
        for(TestHolder test : testSet){
            int[] encoded = test.encoded;
            int first = test.first;
            System.out.println("encoded = " + Arrays.toString(encoded) + "\tfirst = " + first);
            System.out.println("Original Array = " + Arrays.toString(decode(encoded, first)) + '\n');
        }
    }
}