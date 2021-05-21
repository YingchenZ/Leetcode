#include <vector>
#include <iostream>

int jump(std::vector<int>& nums) {
    if(nums.size() == 1)    return 0;
    int totalStep = 0;
    int maxPos = 0;
    int boundary = 0;
    for(int i = 0; i < nums.size() - 1; i++){
        // we will find out all possible position that we can reach from the previous step
        // for every possible position, keep finding the max position that we can reach in the current window
        maxPos = std::max(maxPos, i + nums[i]);

        // when we reach the end of the current window
        if(i == boundary){
            // our next boundary will be the maxPos (max position that we can reach in the current window)
            boundary = maxPos;
            // we need one more step since the previous window is end
            totalStep++;
        }
    }
    return totalStep;
}

// nums = {2,3,1,1,4}
// Minimum Number of Jumps = 2

// nums = {2,3,0,1,4}
// Minimum Number of Jumps = 2


int main(){
    std::vector<std::vector<int>> testSet = {{2,3,1,1,4}, {2,3,0,1,4}};
    for(std::vector<int> test : testSet){
        std::cout << "nums = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == test.size() - 1? "}\n":",");
        }
        std::cout << "Minimum Number of Jumps = " << jump(test) << std::endl << std::endl;
    }
    return 0;
}