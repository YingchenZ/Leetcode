import java.util.*;

class Solution {
    public static int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;

        int[][] dp = new int[m + 1][n + 1];
        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0] == 1) break;
            dp[i + 1][1] = 1;
        }
        for(int i = 0; i < n; i++){
            if(obstacleGrid[0][i] == 1) break;
            dp[1][i + 1] = 1;
        }

        for(int i = 2; i < m + 1; i++){
            for(int j = 2; j < n + 1; j++){
                if(obstacleGrid[i - 1][j - 1] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // for(int i = 0; i < m + 1; i++){
        //     for(int j = 0; j < n+1; j++){
        //         System.out.print(dp[i][j] + " ");
        //     }
        //     System.out.println();
        // }

        return dp[m][n];
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
    // 0 
    // Unique Paths = 1       
    // ===== Test Matrix =====
    // 1 
    // Unique Paths = 0       
    // ===== Test Matrix =====
    // 0 
    // 1 
    // Unique Paths = 0       
    // ===== Test Matrix =====
    // 1 
    // 0 
    // Unique Paths = 0       
    // ===== Test Matrix =====
    // 0 1 
    // Unique Paths = 0       
    // ===== Test Matrix =====
    // 1 0 
    // Unique Paths = 0       
    // ===== Test Matrix =====
    // 0 1 
    // 0 0
    // Unique Paths = 1
    // ===== Test Matrix =====
    // 0 0 0
    // 0 1 0
    // 0 0 0
    // Unique Paths = 2

    public static void main(String[] args){
        int[][][] testSet = {
            {{0}}, {{1}},
            {{0},{1}},{{1},{0}},
            {{0,1}},{{1,0}},
            {{0,1},{0,0}},
            {{0,0,0},{0,1,0},{0,0,0}}
        };

        for(int i = 0; i < testSet.length; i++){
            System.out.println("===== Test Matrix =====");
            printMatrix(testSet[i]);
            System.out.println("Unique Paths = " + uniquePathsWithObstacles(testSet[i]));
        }
    }
}