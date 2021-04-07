#include <vector>
#include <tuple>
#include <iostream>
bool search(std::vector<int>& nums, int target) {
    if(nums.size() == 1) return nums[0] == target;
    int left = 0, right = nums.size() - 1;
    while(left <= right){
        while(left < right && nums[left] == nums[left + 1]){
            left++;
        }
        while(left < right && nums[right] == nums[right - 1]){
            right--;
        }
        
        int mid = (left + right) / 2;
        if(nums[mid] == target) return true;
        if(nums[mid] > target){
            // left > mid => target is on the smaller part
            // or, left <= target => target is on the larger part
            if(nums[left] > nums[mid] || nums[left] <= target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if(nums[left] <= nums[mid] || nums[left] > target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        
        }
    }
    return false;
}

// Test:{1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1}    Target = 2 is found
// Test:{1,1}      Target = 3 is not found
// Test:{3,1}      Target = 0 is not found
// Test:{1,3}      Target = 2 is not found
// Test:{4,5,6,7,0,1,2}    Target = 3 is not found
// Test:{1}        Target = 0 is not found
// Test:{4,5,6,7,0,1,2}    Target = 2 is found
// Test:{4,5,6,7,0,1,2}    Target = 4 is found


int main(){
    std::vector<std::tuple<std::vector<int>, int>> testSet = {
        {{1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1},2},
        {{1,1},3},
        {{3,1},0},  {{1,3},2}, {{4,5,6,7,0,1,2}, 3},
        {{1},0}, {{4,5,6,7,0,1,2},2}, {{4,5,6,7,0,1,2},4}
    };

    for(auto test : testSet){
        std::vector<int> nums = std::get<0>(test);
        std::cout << "Test:{";
        for(int i = 0; i < nums.size(); i++){
            std::cout << nums[i] << (i == (nums.size() - 1)? "}":",");
        }
    
        int target =std::get<1>(test);
       
        std::cout << "\tTarget = " << target << " is " << (search(nums, target)?"found":"not found")<< std::endl;
    }
    return 0;
}