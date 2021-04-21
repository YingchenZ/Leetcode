#include <vector>
#include <iostream>

int minPathSum(std::vector<std::vector<int>>& grid) {
    if(grid.size() == 1 && grid[0].size() == 1) return grid[0][0];
    std::vector<std::vector<int>> dp(grid.size() + 1, std::vector<int>(grid[0].size() + 1,0));

    for(int i = 0; i < grid.size();i++){
        dp[i + 1][1] = grid[i][0];
        dp[i + 1][1] += dp[i][1];
    }
    for(int i = 0; i < grid[0].size();i++){
        dp[1][i + 1] = grid[0][i];
        dp[1][i + 1] += dp[1][i];
    }

    for(int i = 1; i < grid.size(); i++){
        for(int j = 1; j < grid[i].size(); j++){
            // std::cout <<"grid = " << grid[i][j]<< std::endl;
            dp[i + 1][j + 1] = grid[i][j] + std::min(dp[i][j + 1], dp[i + 1][j]);
        }
    }

    return dp[grid.size()][grid[0].size()];
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
// 1  2  3
// 4  5  6
// Minimum Path Sum = 12

// ===== Test Matrix =====
// 1  3  1
// 1  5  1
// 4  2  1
// Minimum Path Sum = 7

int main(){
    std::vector<std::vector<std::vector<int>>> testSet = {
        {
            {1,2,3},
            {4,5,6}
        },
        {
            {1,3,1},
            {1,5,1},
            {4,2,1}
        }
    };
    for(auto test : testSet){
        std::cout << "===== Test Matrix ====="<< std::endl;
        printMatrix(test);
        std::cout << "Minimum Path Sum = "<< minPathSum(test) << std::endl<< std::endl;
    }
    return 0;
}