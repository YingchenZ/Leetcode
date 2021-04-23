#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
    if(nums.size() == 1) return nums;
    sort(nums.begin(), nums.end());
    std::vector<int> dp(nums.size(),1);
    int max = 1;
    for(int i = 0; i < nums.size(); i++){
        // 1 2 4 5 7 8 9 10 11 12 13 14 20
        // 1 2 3 2 2 4 2 3  2  4  2  3  4
        for(int j = 0; j < i; j++){
            if(nums[i] % nums[j] == 0){
                dp[i] = std::max(dp[j] + 1, dp[i]);
                max = std::max(dp[i], max);
            }
        }
    }

    if(max == 1) return {nums[0]};

    std::vector<int> ans = {};
    int prev = -1, next = max;

    for(int i = nums.size() - 1; i >= 0; i--){
        if(dp[i] == next && prev == -1){
            prev = nums[i];
            next--;
            ans.push_back(nums[i]);
        }
        if(dp[i] == next && (prev % nums[i] == 0)){
            ans.push_back(nums[i]);
            prev = nums[i];
            next = dp[i] - 1;
        }
    }

    return ans;
}

// Array = {3,17}  Largest Divisible Subset = {3}
// Array = {1,2,3} Largest Divisible Subset = {3,1}
// Array = {2,3,4,9,8}     Largest Divisible Subset = {8,4,2}
// Array = {3,4,16,8}      Largest Divisible Subset = {16,8,4}
// Array = {1,2,4,7,8,9,10,11,12,13,14,5,20}       Largest Divisible Subset = {20,10,5,1}


int main(){
    std::vector<std::vector<int>> testSet = {
        {3, 17},
        {1,2,3},
        {2,3,4,9,8},
        {3,4,16,8},
        {1,2,4,7,8,9,10,11,12,13,14,5,20}
    };

    for(std::vector<int> test : testSet){
        std::cout << "Array = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << ((i == (test.size() -1)) ? "": ",");
        }
        std::cout << "}\tLargest Divisible Subset = {";
        std::vector<int> answer = largestDivisibleSubset(test);
        for(int i = 0; i < answer.size(); i++){
            std::cout << answer[i] << ((i == (answer.size() -1)) ? "}\n": ",");
        }
    }
    return 0;
}