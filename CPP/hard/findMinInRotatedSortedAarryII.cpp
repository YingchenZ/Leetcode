#include <vector>
#include <iostream>

int findMin(std::vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    if(nums[0] < nums[nums.size() - 1]) return nums[0];

    int left = 0, right = nums.size() - 1;
    int mid = 0;

    while(left < right){
        while(left <right && nums[left] == nums[left + 1]){
            left++;
        }
        while(left <right && nums[right] == nums[right - 1]){
            right--;
        }

        mid = (left + right) / 2;
        
    
        if(nums[mid] > nums[right]){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    
    }
    return nums[left];
}

// Test: {3,1}     Min = 1
// Test: {1,3,5}   Min = 1
// Test: {2,2,0,1,1,2}     Min = 0
// Test: {3,0,1,1,3}       Min = 0
// Test: {1,2,3,4,5,6,7}   Min = 1
// Test: {2,2,2,3,4,4,4,5,5,5,6,0,1,1,1,1,1,1}     Min = 0

int main() {
    std::vector<std::vector<int>> testSet = {
        {3,1},{1,3,5},
        {2,2,0,1,1,2},{3,0,1,1,3},{1,2,3,4,5,6,7},
        {2,2,2,3,4,4,4,5,5,5,6,0,1,1,1,1,1,1}
    };

    for(auto test : testSet) {
        std::cout << "Test: {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == (test.size() - 1)? "}":",");
        }
        std::cout << "\tMin = "<< findMin(test)<< std::endl;
    }
    return 0;
}