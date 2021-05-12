import java.util.*;

class Solution {
    private static class TestHolder{
        public int[] arr;
        public int[][] queries;
        public TestHolder(int[] arr, int[][] queries){
            this.arr = arr;
            this.queries = queries;
        }
    };

    public static int[] xorQueries(int[] arr, int[][] queries) {
        int[] xorArr = new int[arr.length + 1];
        for(int i = 1; i < xorArr.length; i++){
            xorArr[i] = xorArr[i - 1] ^ arr[i - 1];
        }
        int[] ans = new int[queries.length]; 
        for(int i = 0; i < queries.length;i++){
            ans[i] = xorArr[queries[i][1] + 1] ^ xorArr[queries[i][0]];
        }
        return ans;
    }

    // arr = [1, 3, 4, 8]
    // queries = [[0, 1],[1, 2],[0, 3],[3, 3]]
    // XOR = [2, 7, 14, 8]
    
    // arr = [4, 8, 2, 10]
    // queries = [[2, 3],[1, 3],[0, 0],[0, 3]]
    // XOR = [8, 0, 4, 4]

    public static void main(String[] args){
        TestHolder[] testSet = {
            new TestHolder(new int[]{1,3,4,8}, new int[][]{{0,1},{1,2},{0,3},{3,3}}),
            new TestHolder(new int[]{4,8,2,10}, new int[][]{{2,3},{1,3},{0,0},{0,3}})
        };

        for(TestHolder test : testSet){
            System.out.println("arr = " + Arrays.toString(test.arr));
            System.out.print("queries = [");
            for(int i = 0; i < test.queries.length; i++){
                System.out.print(Arrays.toString(test.queries[i]));
                System.out.print((i == test.queries.length - 1)? "]\n":",");
            }
            System.out.println("XOR = " + Arrays.toString(xorQueries(test.arr, test.queries)) + '\n');
        }
    }
}