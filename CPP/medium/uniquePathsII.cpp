#include <vector>
#include <iostream>

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    // if( == 1)  return 1;
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for(int i = 0; i < m; i++){
        if(obstacleGrid[i][0] == 1) break;
        dp[i + 1][1] = 1;
    }
    for(int i = 0; i < n; i++){
        if(obstacleGrid[0][i] == 1) break;
        dp[1][i + 1] = 1;
    }
    dp[1][1] = !obstacleGrid[0][0];
    for(int i = 2; i <= m; i++){
        for(int j = 2; j <= n; j++){
            if(obstacleGrid[i - 1][j - 1]) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m][n];
}


void printMatrix(std::vector<std::vector<int>> matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int n : matrix[i]){
            std::cout << n<<"  ";
        }
        std::cout << std::endl;
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
// 0  1
// Unique Paths = 0

// ===== Test Matrix =====
// 1  0
// Unique Paths = 0

// ===== Test Matrix =====
// 0  1
// 0  0
// Unique Paths = 1

// ===== Test Matrix =====
// 0  0  0
// 0  1  0
// 0  0  0
// Unique Paths = 2

int main(){
    std::vector<std::vector<std::vector<int>>> testSet = {
        {{0}}, {{1}},
        {{0},{1}},{{1},{0}},
        {{0,1}},{{1,0}},
        {{0,1},{0,0}},
        {{0,0,0},{0,1,0},{0,0,0}}
    };
    for(auto test : testSet){
        std::cout << "===== Test Matrix ====="<< std::endl;
        printMatrix(test);
        std::cout << "Unique Paths = "<< uniquePathsWithObstacles(test) << std::endl<< std::endl;
    }
    return 0;
}