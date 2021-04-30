#include <vector>
#include <algorithm>
#include <iostream>

int singleNumber(std::vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i+=3){
        if(i == nums.size() - 1 || nums[i] != nums[i + 1]){
            return nums[i];
        }
    }
    return nums[nums.size() - 1];
}

// nums = [2,2,3,2]
// The single element = 3

// nums = [-2,-2,1,1,4,1,4,4,-4,-2]
// The single element = -4

// nums = [0,1,0,1,0,1,2,2,2,3,99,99,99]
// The single element = 3

int main(){
    std::vector<std::vector<int>> testSet = {
        {2,2,3,2},
        {-2,-2,1,1,4,1,4,4,-4,-2},
        {0,1,0,1,0,1,2,2,2,3,99,99,99}
    };

    for(std::vector<int> test : testSet){
        std::cout << "nums = [";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == (test.size() - 1)? "]\n": ",");
        }
        std::cout << "The single element = "<< singleNumber(test) << std::endl << std::endl;
    }

    return 0;
}