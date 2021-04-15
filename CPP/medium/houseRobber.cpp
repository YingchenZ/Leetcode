#include <vector>
#include <utility>
#include <iostream>

int rob(std::vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    int dp[nums.size() + 1];
    dp[0] = 0;
    dp[1] = nums[0];

    for(int i = 1; i < nums.size(); i++){
        dp[i + 1] = std::max(nums[i] + dp[i - 1], dp[i]);
    }

    return dp[nums.size()];
}

// Test = {1,2,3,1}        => 4
// Test = {2,7,9,3,1}      => 12

int main(){
    std::vector<std::vector<int>> testSet = {
        {1,2,3,1},
        {2,7,9,3,1}
    };

    for(std::vector<int> test : testSet){
        std::cout << "Test = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == (test.size() - 1)? "}\t=> ":",");
        }
        std::cout << rob(test)<< std::endl;
    }

    return 0;
}