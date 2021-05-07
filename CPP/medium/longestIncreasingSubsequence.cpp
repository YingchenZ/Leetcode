#include <vector>
#include <utility>
#include <iostream>

int lengthOfLIS(std::vector<int>& nums) {
    std::vector<int> dp(nums.size(), 1);
    int maxAns = 1;
    for(int i = 1; i < nums.size(); i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        maxAns = std::max(maxAns, dp[i]);
    }
    return maxAns;
}

// nums = {0,1,0,3,2,3}    Length of the Longest Increasing Subsequence = 4
// nums = {4,10,4,3,8,9}   Length of the Longest Increasing Subsequence = 3
// nums = {10,9,2,5,3,7,101,18}    Length of the Longest Increasing Subsequence = 4

int main(){
    std::vector<std::vector<int>> testSet = {
        {0,1,0,3,2,3},
        {4,10,4,3,8,9},
        {10,9,2,5,3,7,101,18}
    };

    for(std::vector<int> test : testSet){
        std::cout << "nums = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == (test.size() - 1)? "}\t":",");
        }
        std::cout << "Length of the Longest Increasing Subsequence = " << lengthOfLIS(test) << std::endl;
    }

    return 0;
}