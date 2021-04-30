#include <vector>
#include <iostream>

int findDuplicate(std::vector<int>& nums) {
    int ans = nums[0];
    for(int num: nums){
        int index = num;
        if(index < 0){
            index = -index;
        }
        if(nums[index] < 0) return index;
        nums[index] *= -1;
    }
    return ans;
}

// nums = {1,1}
// Duplicate Number = 1

// nums = {1,2,1}
// Duplicate Number = 1

// nums = {1,3,4,2,2}
// Duplicate Number = 2

// nums = {3,1,3,4,2}
// Duplicate Number = 3

int main(){
    std::vector<std::vector<int>> testSet = {
        {1,1},
        {1,2,1},
        {1,3,4,2,2},
        {3,1,3,4,2}
    };

    for(std::vector<int> test : testSet){
        std::cout << "nums = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == (test.size() - 1)? "}\n":",");
        }
        std::cout << "Duplicate Number = "<< findDuplicate(test)<< std::endl << std::endl;
    }
    return 0;
}