#include <iostream>
#include <algorithm>
#include <vector>
std::vector<vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result = std::vector<std::vector<int>>();
    int sizeOfList = nums.size();
    if(sizeOfList == 0){
        return result;
    }
    std::sort(nums.begin(),nums.end());

    for(int i = 0; i < sizeOfList; i++){
        if(i == 0 or nums[i] != nums[i - 1]){
            int last = sizeOfList -1;
            for(int j = i + 1; j < sizeOfList; j++){
                if(j == i + 1 or nums[j] != nums[j - 1]){
                    while(last > j && nums[last] > -nums[i] - nums[j]){
                        last--;
                    }
                    if(j == last){
                        break;
                    }
                    if(nums[i] + nums[j] == -nums[last]){
                        result.push_back(std::vector<int>{nums[i], nums[j], nums[last]});
                    }
                }
            }
        }
    }
    return result;
}

// [-1,0,1,2,-1,-4]     => [[-1,-1,2],[-1,0,1]]
// [1,-1,-1,0]          => [[-1,0,1]]
// []                   => []
// [0]                  => []
// [1,2,3,4,5,-3]       => [[-3,1,2]]
// [0,0,0, 0,0,0]       => [[0,0,0]]
int main(){
    int result= threeSum(std::vector<int>(-1,0,1,2,-1,-4));
    for(int i = 0; i < result.size(); i++){
        std::cout<< result[i] <<" "<<std::endl;
    }
    return 0;
}