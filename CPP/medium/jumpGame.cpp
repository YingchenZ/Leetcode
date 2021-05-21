#include <vector>
#include <iostream>

bool canJump(std::vector<int> nums) {

    int maxPos = 0;
    for(int i = 0; i < nums.size(); i++){
        if(i <= maxPos){
            maxPos = std::max(maxPos, i + nums[i]);
            if(maxPos >= nums.size() - 1)    return true;
        }

    }
    return maxPos >= nums.size() - 1;
}

// nums = {2,3,1,1,4}
// Can reach the end?    True

// nums = {3,2,1,0,4}
// Can reach the end?    False

int main(){
    std::vector<std::vector<int>> testSet = {{2,3,1,1,4}, {3,2,1,0,4}};
    for(std::vector<int> test : testSet){
        std::cout << "nums = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == test.size() - 1? "}\n":",");
        }
        std::cout << "Can reach the end?    " << (canJump(test)? "True" :"False") << std::endl << std::endl;
    }
    return 0;
}