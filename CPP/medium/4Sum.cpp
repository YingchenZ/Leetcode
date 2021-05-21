#include <vector>
#include <algorithm>
#include <iostream>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> ans = {};
    if(nums.size() <= 3)    return ans;
    std::sort(nums.begin(), nums.end());
    
    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i - 1])  continue;

        for(int j = i + 1; j < nums.size(); j++){
            if(j > i + 1 && nums[j] == nums[j - 1])  continue;
            int left = j + 1, right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if(sum == target){
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    while(left < right && nums[left] == nums[left -1]){
                        left++;
                    }
                }
                else if(sum > target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
    }
    return ans;
}

void printMatrix(std::vector<std::vector<int>> matrix){
    if(matrix.size() == 0) std::cout << "{}";
    for(int i = 0; i < matrix.size(); i++){
        std::cout << "{";
        for(int j = 0; j < matrix[i].size(); j++){
            std::cout << matrix[i][j] << (j == (matrix[i].size() - 1)?"}":", ") ;
        }
        std::cout << (i == (matrix.size() - 1)?"":", ");
    }
    std::cout << std::endl;
}

struct TestHolder{
    std::vector<int> nums;
    int target;
    TestHolder(std::vector<int> nums, int target) : nums(nums), target(target) {}
};

// nums = {2,2,2,2,2},     target = 8
// Ans = {2, 2, 2, 2}

// nums = {1,0,-1,0,-2,2}, target = 0
// Ans = {-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}

int main(){
    std::vector<TestHolder*> testSet = {
        new TestHolder({2,2,2,2,2}, 8),
        new TestHolder({1,0,-1,0,-2,2}, 0)
    };

    for(TestHolder* test : testSet){
        std::cout << "nums = {";
        for(int i = 0; i < test->nums.size(); i++){
            std::cout << test->nums[i] << (i == test->nums.size() - 1? "},\t" :",");
        }
        std::cout << "target = " << test->target << std::endl;
        std::vector<std::vector<int>> ans = fourSum(test->nums, test->target);
        std::cout << "Ans = ";
        printMatrix(ans);
        std::cout << std::endl;
    }

    return 0;
}