#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
int threeSumClosest(std::vector<int> nums, int target) {
    if(nums.size() == 1) return nums[0];
    sort(nums.begin(), nums.end());
    
    int min = nums[0] + nums[1] + nums[nums.size() - 1];

    for(int i = 0; i < nums.size() - 2; i++){
        int left = i + 1, right = nums.size() - 1;
        while(left < right){
            int current = nums[i] + nums[left] + nums[right];
            if(current > target){
                right--;
            }
            else{
                left++;
            }
            if(abs(target - min) > abs(target - current)){
                min = current;
            }
        }
    }
    return min;
}

// Test = {-1,2,1,-4} Target = 1
// The closest sum = 2

// Test = {1,1,1,0} Target = -100
// The closest sum = 2

// Test = {0,2,1,-3} Target = 1
// The closest sum = 0

int main(){
    std::vector<std::pair<std::vector<int>, int>> testSet = {
        {{-1,2,1,-4}, 1},   {{1,1,1,0}, -100}, {{0,2,1,-3},1}
    };
    for(auto test : testSet){
        std::cout<< "Test = {";
        for(int i = 0; i < test.first.size(); i++){
            std::cout << test.first[i] << (i == (test.first.size() - 1)? "} ":",");
        }
        std::cout<< "Target = "<< test.second <<  std::endl;
        std::cout << "The closest sum = "<< threeSumClosest(test.first, test.second) << std::endl << std::endl;
    }


    return 0;
}