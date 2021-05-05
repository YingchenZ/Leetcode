#include <vector>
#include <algorithm>
#include <iostream>

int rob(std::vector<int> nums) {
    if(nums.size() == 1) return nums[0];
    int dp[nums.size() + 1];
    dp[0] = 0;
    dp[1] = nums[0];

    for(int i = 1; i < nums.size(); i++){
        dp[i + 1] = std::max(nums[i] + dp[i - 1], dp[i]);
    }

    return dp[nums.size()];
}

int deleteAndEarn(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());
    int maxEle = nums[nums.size() - 1]; 
    std::vector<int> dp(maxEle+ 1, 0);
    dp[0] = 0;
    
    for(int i = 0; i < nums.size(); i++){
        dp[nums[i]] += nums[i];
    }        
    return rob(dp);
}

// Test = {3,4,2}  => 6
// Test = {2,2,3,3,3,4}    => 9
// Test = {1,1,1,2,4,5,5,5,6}      => 18

int main(){
    std::vector<std::vector<int>> testSet = {
        {3,4,2},
        {2,2,3,3,3,4},
        {1,1,1,2,4,5,5,5,6}
    };

    for(std::vector<int> test : testSet){
        std::cout << "Test = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == (test.size() - 1)? "}\t=> ":",");
        }
        std::cout << deleteAndEarn(test)<< std::endl;
    }

    return 0;
}