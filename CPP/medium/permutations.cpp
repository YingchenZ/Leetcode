#include <vector>
#include <iostream>

void produce(std::vector<int> nums, std::vector<int> temp, std::vector<std::vector<int>>& ans){
    if(temp.size() == nums.size()){
        ans.emplace_back(temp);
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] >= -10){
            temp.push_back(nums[i]);
            // indicate that this number is visited
            nums[i] -= 21;
            produce(nums, temp, ans);
            // mark this num as not visited
            nums[i] += 21;
            temp.pop_back();
        }
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> ans = {};
    produce(nums, std::vector<int>{}, ans);
    return ans;
}

// nums = {1}
// Possible Permutations = {{1}}

// nums = {0,1}
// Possible Permutations = {{0,1}, {1,0}}

// nums = {1,2,3}
// Possible Permutations = {{1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}}

int main(){
    std::vector<std::vector<int>> testSet = {{1},{0,1},{1,2,3}};
    for(std::vector<int> test : testSet){
        std::cout << "nums = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == test.size() - 1 ? "}\n":",");
        }
        std::cout << "Possible Permutations = {";
        std::vector<std::vector<int>> ans = permute(test);
        for(int k = 0; k < ans.size(); k++){
            std::cout << "{";
            for(int i = 0; i < ans[k].size(); i++){
                std::cout << ans[k][i] << (i == ans[k].size() - 1 ? "}":",");
            }
            std::cout << (k == ans.size() - 1?"}\n":", ");
        }
        std::cout << std::endl;
    }
    return 0;
}