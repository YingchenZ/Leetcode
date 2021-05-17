#include <vector>
#include <iostream>

int findPeakElement(std::vector<int>& nums) {
    if(nums.size() == 1)    return 0;
    if(nums.size() == 2)    return (nums[0] < nums[1])? 1 : 0;
    int left = 0, right = nums.size() - 1;
    int mid = -1;
    while(left <= right){
        mid = (left + right) / 2;
        if(mid == 0 && nums[mid + 1] < nums[mid]){
            return mid;
        }
        else if(mid == nums.size() - 1 && nums[mid - 1] < nums[mid]){
            return mid;
        }
        else if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]){
            
            return mid;
        }
        else if(nums[mid] < nums[mid + 1]){
            left = mid + 1;
        }
        else {
            right = mid;
        }
        
    }

    return mid;
}

// nums = {1,2}
// Index of one of the peak numbers = 1

// nums = {3,1,2}
// Index of one of the peak numbers = 2

// nums = {1,2,3,1}
// Index of one of the peak numbers = 2

// nums = {3,4,3,2,1}
// Index of one of the peak numbers = 1

// nums = {1,2,1,3,5,6,4}
// Index of one of the peak numbers = 5

int main(){
    std::vector<std::vector<int>> testSet = {
            {1,2},
            {3,1,2},
            {1,2,3,1},
            {3,4,3,2,1},
            {1,2,1,3,5,6,4}
    };
    for(std::vector<int> test : testSet){
        std::cout << "nums = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == test.size() - 1? "}\n":",");
        }
        std::cout << "Index of one of the peak numbers = " << findPeakElement(test) << std::endl << std::endl;
    }
    
    return 0;
}