#include <vector>
#include <iostream>

int rob(std::vector<int>& nums) {
    if(nums.size() == 1) return nums[0];

    std::vector<int> robOrNot(nums.size() + 1, 0);
    
    // Rob the first one
    robOrNot[1] = nums[0];
    for(int i = 1; i < nums.size() - 1; i++){
        robOrNot[i + 1] = std::max(robOrNot[i], nums[i] +robOrNot[i - 1]);
    }
    // save the max 
    robOrNot[nums.size()] = robOrNot[nums.size() - 1];

    // Not rob the first
    robOrNot[1] = nums[1];
    for(int i = 2; i < nums.size(); i++){
        robOrNot[i] = std::max(robOrNot[i-1], nums[i] +robOrNot[i - 2]);
    }

    return  std::max(robOrNot[nums.size()], robOrNot[nums.size() - 1]);
    
}

// Test = {4,1,2}  => Max = 4
// Test = {1,2,1,1}        => Max = 3
// Test = {1,1,1,0}        => Max = 2

int main(){
    std::vector<std::vector<int>> testSet = {
       {4,1,2}, {1,2,1,1},{1,1,1,0}
    };

    for(std::vector<int> test : testSet){
        std::cout << "Test = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == (test.size() - 1)? "}\t=> Max = ":",");
        }
        std::cout << rob(test)<< std::endl;
    }
}