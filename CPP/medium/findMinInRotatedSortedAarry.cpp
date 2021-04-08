#include <vector>
#include <iostream>

int findMin(std::vector<int>& nums) {
    if(nums.size() == 1) return nums[0];

    int left = 0, right = nums.size() - 1;
    int smallest = nums[0];
    while(left <= right){
        int mid = (left + right) / 2;
        
        if(nums[mid] < smallest){
            smallest = nums[mid];
        }
        // if nums[mid] >= nums[right] -> min has to be on the right side since everything before mid is less than it
        if(nums[mid] >= nums[right]){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    
    return smallest;
}

// Test: {3,4,5,1,2}       Min = 1
// Test: {4,5,6,7,0,1,2}   Min = 0
// Test: {11,13,15,17}     Min = 11

int main(){
    std::vector<std::vector<int>> testSet = {
        {3,4,5,1,2},
        {4,5,6,7,0,1,2},
        {11,13,15,17}
    };

    for(auto test : testSet){
        std::cout << "Test: {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == (test.size() - 1)? "}":",");
        }
    
      
       
        std::cout << "\tMin = "<< findMin(test)<< std::endl;
    }
    return 0;
}