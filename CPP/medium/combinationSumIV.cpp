#include <vector>
#include <iostream>

int combinationSum4(std::vector<int>& nums, int target) {
    std::vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= target; i++){
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] <= i && dp[i] < INT_MAX -  dp[i - nums[j]]){
                dp[i] += dp[i - nums[j]];
            }
        }
    }

    return dp[target];
}

// Test array   => {3,2,1} Target = 4
// Number of Possible Combinations = 7

// Test array   => {1,2,3,4,5,6,7,8,9,10,11,12,13,14,16,19,40,50,560}      Target = 7
// Number of Possible Combinations = 64

int main(){
    std::vector<std::pair<std::vector<int>,int>> testSet = {
        {{3,2,1},4},
        {{1,2,3,4,5,6,7,8,9,10,11,12,13,14,16,19,40,50,560},7}
    };
    for(auto test : testSet){
        std::cout << "Test array   => {";
        for(int i = 0; i < test.first.size(); i++){
            std::cout << test.first[i] << (i == (test.first.size() - 1)? "}\t":",");
        }
        std::cout << "Target = "<< test.second << std::endl;

        std::cout << "Number of Possible Combinations = " << combinationSum4(test.first, test.second)<< std::endl << std::endl;
    }
    return 0;
}