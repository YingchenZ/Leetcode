#include <vector>
#include <tuple>
#include <iostream>


int search(std::vector<int>& nums, int target) {
    if(nums.size() == 0) return (nums[0] == target)? 0: -1;

    int left = 0, right = nums.size() - 1;
    int mid = 0;
    while(left <= right){
        mid = (left + right) / 2;

        if(nums[mid] == target) return mid;

        if(nums[mid] > target){
            if(nums[mid] < nums[left] || target >= nums[left]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if(nums[mid] >= nums[left] || target < nums[left]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }
    return -1;
}

// Test: 3 1
// 0 is at Index -1

// Test: 1 3
// 2 is at Index -1

// Test: 4 5 6 7 0 1 2
// 3 is at Index -1

// Test: 1
// 0 is at Index -1

// Test: 4 5 6 7 0 1 2
// 2 is at Index 6

// Test: 4 5 6 7 0 1 2
// 4 is at Index 0

int main(){
    std::vector<std::tuple<std::vector<int>, int>> testSet = {
        {{3,1},0},  {{1,3},2}, {{4,5,6,7,0,1,2}, 3},
        {{1},0}, {{4,5,6,7,0,1,2},2}, {{4,5,6,7,0,1,2},4}
    };

    for(auto test : testSet){
        std::vector<int> nums = std::get<0>(test);
        std::cout << "Test:";
        for(auto num : nums){
            std::cout << " " << num;
        }
        std::cout<< std::endl;
        int target =std::get<1>(test);
        std::cout << target << " is at Index " << search(nums, target)<< std::endl << std::endl;
    }
    return 0;
}