#include <vector>
#include <iostream>

std::vector<int> searchRange(std::vector<int>& nums, int target) {
    if(nums.size() == 0)    return {-1, -1};
        if(nums.size() == 1){
            if(nums[0] == target){
                return {0,0};
            }
            else{
                return {-1,-1};
        }
    }
    
    std::vector<int> result(2, -1);

    // find the first position
    int left = 0, right = nums.size() -1;
    int mid = -1;
    while(left <= right){
        mid = (right + left) / 2;
        int midLeft = mid - (mid != 0);
        int midRight = (mid == nums.size() -1)? mid:mid+1;

        if( nums[mid] != target && nums[midRight] == target && nums[midLeft] <= nums[mid] && nums[mid] < nums[midRight]){
            break;
        }
        if(nums[mid] > target){
            right = mid - 1;
        }
        else if(nums[mid] == target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }  
    mid++;

    if(mid == nums.size()){
        return {-1,-1};
    } 
    if(nums[mid] == target && mid == nums.size() - 1){
        return {mid - (nums[mid-1] == target) , mid};
    }
    if(nums[mid] != target && mid == 1 && nums[mid-1] == target){
        return {mid-1 , mid-1};
    }
    if(nums[mid] != target){
        return {-1,-1};
    }

    result[0] = mid - (nums[mid-1] == target);

    right = nums.size() - 1;
    left = mid + 1;
    while(left <= right){
        mid = (right + left) / 2;
        int midLeft = mid - (mid != 0);
        int midRight = (mid == nums.size() -1)? mid:mid+1;
    
        if( nums[mid] == target  && nums[midLeft] <= nums[mid] && nums[mid] < nums[midRight]){
            break;
        }
        if(nums[mid] > target){
            right = mid -1;
        }   
        else{
            left = mid + 1;
        }
    } 

    if(nums[mid] != target)
        mid--;
    result[1] = mid;
    return result;
}  


// Test List = 0 1 1 2 3 3 3 3 3 3 4 4 4 5 5 7 8
// 0 => Start = 0 End = 0
// 1 => Start = 1 End = 2
// 2 => Start = 3 End = 3
// 3 => Start = 4 End = 9
// 4 => Start = 10 End = 12
// 5 => Start = 13 End = 14
// 6 => Start = -1 End = -1
// 7 => Start = 15 End = 15
// 8 => Start = 16 End = 16

int main(){
    std::vector<int> test = {0,1,1,2,3,3,3,3,3,3,4,4,4,5,5,7,8};
    std::cout << "Test List =";
    for(auto i : test){
        std::cout << " "<< i;
    }
    std::cout << std::endl;
    for(int i = 0; i <= 8; i++){
        std::vector<int> ans = searchRange(test, i);
        std::cout << i << " => Start = " << ans[0] << " End = "<< ans[1] << std::endl;
    }
    
    return 0;
}