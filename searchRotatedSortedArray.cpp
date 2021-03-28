#include <vector>
#include <tuple>
#include <iostream>


int search(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid = 0;

    int midLeft = 0, midRight = 0;

    if(nums.size() == 0)    return -1;

    while(left <= right){
        mid = (right + left) / 2;
        
        midRight = (mid + 1 == nums.size())? mid: mid + 1;
        midLeft = (mid == 0)? 0 : mid - 1;
        
        if(nums[midLeft] >= nums[mid] && nums[mid] <= nums[midRight])
            break;
        if(nums[mid] == target) return mid;
        // if middle > rightMost, 
        if(nums[mid] > nums[nums.size()-1]){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    if(target == nums[mid])
        return mid;

    int largest = (mid == 0)? 0 : mid - 1;
    int smallest = mid;
    if(nums[largest] <= nums[nums.size() - 1]) largest = nums.size() - 1;
    if(nums[0] <= nums[mid] ) smallest = 0;
    
    int lower = -1, upper = -1;
    if(target >= nums[0] && target <= nums[largest]){
        lower = 0;
        upper = largest;
    }
    
    if(target >= nums[smallest] && target <= nums[nums.size()-1]){
        lower = smallest;
        upper = nums.size()-1;
    }
    
    if(lower == -1 || upper == -1) return -1;

    while(lower <= upper ){
        mid = (upper + lower) / 2;
        
        // if mid > target
        if(nums[mid] == target) break;
        if(nums[mid] > target){
            upper = mid - 1;
        }
        else{
            lower = mid + 1;
        }

    }
    
    return nums[mid] == target ? mid : -1;
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
        std::cout << target << " is at Index " << search(nums, target)<< std::endl;
    }
    return 0;
}