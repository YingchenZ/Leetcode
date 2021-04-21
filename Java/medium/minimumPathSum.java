import java.util.*;

class Solution {
    public static int minPathSum(int[][] grid) {
        int[][] dp = new int[grid.length + 1][grid[0].length + 1];
        
        for(int i = 0; i < grid.length; i++){
           dp[i + 1][1] = grid[i][0] + dp[i][1];
        }

        for(int i = 0; i < grid[0].length; i++){
           dp[1][i + 1] = grid[0][i] + dp[1][i];
        }

        for(int i = 1; i < grid.length; i++){
            for(int j = 1; j < grid[i].length; j++){
                dp[i + 1][j + 1] = grid[i][j] + Math.min(dp[i][j + 1], dp[i + 1][j]);
            }
        }

        return dp[grid.length][grid[0].length];
    }

    public static void printMatrix(int[][] matrix){
        for(int[] row : matrix){
            for (int is : row) {
                System.out.print(is + " ");
            }
            System.out.println();
        }
    }

    // ===== Test Matrix =====
    // 1 2 3 
    // 4 5 6 
    // Minimum Path Sum = 12  
    
    // ===== Test Matrix =====
    // 1 3 1 
    // 1 5 1 
    // 4 2 1 
    // Minimum Path Sum = 7

    public static void main(String[] args) {
        List<int[][]> testSet = new ArrayList<>();
        testSet.add(new int[][]{{1,2,3},{4,5,6}});
        testSet.add(new int[][]{{1,3,1},{1,5,1},{4,2,1}});

        for(int[][] test : testSet){
            System.out.println("===== Test Matrix =====");
            printMatrix(test);
            System.out.println("Minimum Path Sum = " + minPathSum(test) + '\n');
        }
    }
}