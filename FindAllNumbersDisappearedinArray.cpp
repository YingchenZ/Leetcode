#include <iostream>
#include <vector>
std::vector<int> findDisappearedNumbers(std::vector<int> nums) {
        std::vector<int> ans = {};
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                if(nums[nums[i] - 1] > 0)
                    nums[nums[i] - 1] = -nums[nums[i] - 1];
            }
            else{
                if(nums[-nums[i] - 1] > 0)
                    nums[-nums[i] - 1] = -nums[-nums[i] - 1];
            }

        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
        }

        return ans;
    }
int main(){
    std::vector<int> ans = findDisappearedNumbers(std::vector<int>{4,3,2,7,8,2,3,1});
    for(int num : ans){
        std::cout<< num<<" ";
    }
    return 0;
}