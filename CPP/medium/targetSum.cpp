#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

class Solution {
private:
    std::unordered_map<std::string, int> dp = {};
public:
    long long helper(std::vector<int> nums, int target, int current, int tempSum){
        if(current == nums.size()){
            return target == tempSum? 1: 0;
        }
        // make a key
        std::string key = std::to_string(current) + "," + std::to_string(tempSum);
        // if this key doesn't exist, add it
        if(dp.count(key) == 0){
            // since every element has two options, + or -
            // we do both of them
            dp[key] = helper(nums, target, current+1, tempSum + nums[current]) + helper(nums, target, current + 1, tempSum - nums[current]);
        }
        
        return dp[key];
    }

    int findTargetSumWays(std::vector<int>& nums, int S) {
        if(nums.size() == 1)    return std::abs(S) == std::abs(nums[0]);
        return helper(nums, S, 0, 0);
    }
};

struct TestHolder{
    std::vector<int> nums;
    int target;
    TestHolder(std::vector<int> n, int t) : nums(n), target(t){}
};

void print(std::vector<int> arr){
    std::cout << "{";
    for(int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << (i == arr.size() - 1? "}":",");
    }
}

// nums = {1}      target = 1
// Number of different expressions = 1

// nums = {1,1,1,1,1}      target = 3
// Number of different expressions = 5

int main(){
    std::vector<TestHolder*> testSet = {
        new TestHolder({1}, 1),
        new TestHolder({1,1,1,1,1},3)
    };

    for(TestHolder* test : testSet){
        Solution* sol = new Solution();
        std::cout << "nums = ";
        print(test->nums);
        std::cout <<"\ttarget = "<< test->target << std::endl;
        std::cout << "Number of different expressions = " << sol->findTargetSumWays(test->nums, test->target) << std::endl << std::endl;
    }
}