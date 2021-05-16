#include <vector>
#include <iostream>

void produce(std::vector<std::vector<int>>& ans, std::vector<int> nums, int start, std::vector<int> temp){
    ans.push_back(temp);
    for(int i = start; i < nums.size(); i++){
        temp.push_back(nums[i]);
        produce(ans, nums, i + 1, temp);
        temp.pop_back();
    }
    return;
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> ans = {};
    produce(ans,nums, 0,{});
    return ans;
}

// nums = {1}
// Reuslt = {{}, {1}}

// nums = {1,2}
// Reuslt = {{}, {1}, {1,2}, {2}}

// nums = {1,2,3}
// Reuslt = {{}, {1}, {1,2}, {1,2,3}, {1,3}, {2}, {2,3}, {3}}

int main(){
    std::vector<std::vector<int>> testSet = {{1}, {1,2}, {1,2,3}};

    for(std::vector<int> test : testSet){
        std::cout << "nums = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == test.size() - 1? "}\n":",");
        }
        std::vector<std::vector<int>> ans = subsets(test);
        std::cout << "Reuslt = {";
        for(int i = 0; i < ans.size(); i++){
            std::cout << "{";
            if(ans[i].size() == 0){
                std::cout << "}";
            }
            for(int j = 0; j < ans[i].size(); j++){

                std::cout << ans[i][j] << (j == ans[i].size() - 1? "}":",");
            }
            std::cout << (i == ans.size() - 1? "}\n\n":", ");
        }
    }
    return 0;
}