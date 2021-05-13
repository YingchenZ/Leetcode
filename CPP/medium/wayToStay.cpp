#include <vector>
#include <iostream>

int numWays(int steps, int arrLen) {
    // the max column of the dp can only be the arrlen or steps / 2
    // we want to find the smaller one to ensure that "The pointer should not be placed outside the array"
    int col = std::min(arrLen - 1, steps / 2);
    std::vector<int> dp(col + 1);
    dp[0] = 1;
    
    for(int i = 1; i <= steps; i++){
        // create a vector to store the all the data for current step - 1
        std::vector<int> prevLine = dp;
        for(int j = 0; j <= col; j++){
            // stay => step - 1 while the pointer doesn't change
            long long ans = prevLine[j];

            // Can move left => step - 1, pointer - 1;
            if (j - 1 >= 0) {
                ans += prevLine[j - 1];
            }
            // Can move right => step - 1, pointer + 1;
            if (j + 1 <= col) {
                ans += prevLine[j + 1];
            }
            dp[j] = ans % 1000000007;
            
        }
        
    }
    return dp[0];
}

// steps = 3       arrLen = 2
// Number of Ways that the pointer will stay at index 0 = 4

// steps = 2       arrLen = 4
// Number of Ways that the pointer will stay at index 0 = 2

// steps = 4       arrLen = 2
// Number of Ways that the pointer will stay at index 0 = 8

// steps = 500     arrLen = 1000000
// Number of Ways that the pointer will stay at index 0 = 374847123

int main(){
    std::vector<std::vector<int>> testSet = {
        {3,2},{2,4},{4,2},{500, 1000000}
    };
    
    for(std::vector<int> test : testSet){
        std::cout << "steps = " << test[0] << "\tarrLen = " << test[1] << std::endl;
        std::cout << "Number of Ways that the pointer will stay at index 0 = " << numWays(test[0], test[1]) << std::endl << std::endl;
    }

    return 0;
}