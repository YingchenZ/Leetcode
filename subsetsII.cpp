#include <vector>
#include <algorithm>
#include <iostream>

void helper(std::vector<std::vector<int>>& result, int startIndex, std::vector<int> tempChoice, std::vector<int> nums){
    result.push_back(tempChoice);
    for(int i = startIndex; i < nums.size(); i++){
        if(i > startIndex && nums[i] == nums[i-1]) continue;
        tempChoice.push_back(nums[i]);
        
        helper(result, i + 1, tempChoice, nums);
        tempChoice.pop_back();
    }
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int> nums) {
    if(nums.size() == 0) return {};
    
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;
    std::vector<int> choice;
    helper(result, 0, choice, nums);
    return result;
}

// ======== Test ========
// 1 2 2
// ======== Subset ========
// {}  {1}  {1,2}  {1,2,2}  {2}  {2,2}
// ======== Test ========
// 0
// ======== Subset ========
// {}  {0}

int main(){
    std::vector<std::vector<int>> testSet = {
        {1, 2, 2},
        {{0}}
    };

    for(auto test : testSet){
        std::cout << "======== Test ========"<< std::endl;
        for(auto num : test){
            std::cout << num << " ";
        }
        std::cout << "\n======== Subset ========"<<std::endl;
        std::vector<std::vector<int>> result = subsetsWithDup(test);
        for(auto r : result){
            std::cout << "{";
            for(int i = 0; i < r.size(); i++){
                std::cout << r[i] << ((i == (r.size() -1)) ? "": ",");
            }
            std::cout << "}  ";
        }
        std::cout << std::endl;
    }
}