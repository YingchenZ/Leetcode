#include <vector>
#include <iostream>

int uniquePaths(int m, int n) {
    if(m == 1)  return 1;

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 1));
    dp[1][1] = 0;
    for(int i = 2; i <= m; i++){
        for(int j = 2; j <= n; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        }
    }
    return dp[m][n];
}

// 3 * 2 Grid      Unique Paths = 3
// 3 * 7 Grid      Unique Paths = 28
// 6 * 5 Grid      Unique Paths = 126
// 7 * 8 Grid      Unique Paths = 1716

int main(){
    std::vector<std::vector<int>> testSet= {
        {3,2}, {3,7},
        {6,5}, {7,8}
    };

    for(std::vector<int> test: testSet){
        std::cout << test[0] << " * "<< test[1] << " Grid\tUnique Paths = "<< uniquePaths(test[0], test[1])<< std::endl;
    }

    return 0;
}