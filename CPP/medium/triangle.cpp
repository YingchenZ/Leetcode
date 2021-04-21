#include <vector>
#include <iostream>

int minimumTotal(std::vector<std::vector<int>>& triangle) {
    if(triangle.size() == 1 && triangle[0].size() == 1) return triangle[0][0];
    std::vector<std::vector<int>> dp(triangle.size() + 1, std::vector<int>(triangle[triangle.size()-1].size() + 1, INT_MAX));
    dp[1][1] = triangle[0][0];

    int min = INT_MAX;
    for(int i = 0; i < triangle.size()-1; i++){
        min = INT_MAX;
        for(int j = 0; j < triangle[i].size(); j++){
            dp[i + 2][j + 1] = std::min(dp[i + 2][j + 1], dp[i + 1][j + 1] + triangle[i + 1][j]);
            dp[i + 2][j + 2] = triangle[i + 1][j + 1] + dp[i + 1][j + 1];

            min = std::min(min, std::min(dp[i + 2][j + 2],dp[i + 2][j + 1]));
        }
    }
    return min;
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
// -10
// Minimum Path Sum from Top to Bottom = -10

// ===== Test Matrix =====
// 1
// 2  3
// Minimum Path Sum from Top to Bottom = 3

// ===== Test Matrix =====
// 2
// 3  4
// 6  5  7
// 4  1  8  3
// Minimum Path Sum from Top to Bottom = 11

int main(){
    std::vector<std::vector<std::vector<int>>> testSet = {
        {
            {-10}
        },
        {
            {1},
            {2,3}
        },
        {
            {2},
            {3,4},
            {6,5,7},
            {4,1,8,3}
        }
    };

    for(auto test : testSet){
        std::cout << "===== Test Matrix ====="<< std::endl;
        printMatrix(test);
        std::cout << "Minimum Path Sum from Top to Bottom = "<< minimumTotal(test) << std::endl<< std::endl;
    }
    return 0;
}