#include <vector>
#include <utility>
#include <iostream>

int maxArea(std::vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxVol = 0;
    while(left <= right){
        int currentVol = std::min(height[left], height[right]) * (right - left);
        maxVol = std::max(maxVol, currentVol);

        // find the smaller one and move them
        // If we keep the smaller one and move the pointer of the larger one
        // the total size will decrease continously
        if(height[left] <= height[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return maxVol;
}

// height = {1,1}
// Max Area = 1

// height = {1,2,1}
// Max Area = 2

// height = {4,3,2,1,4}
// Max Area = 16

// height = {1,8,6,2,5,4,8,3,7}
// Max Area = 49

int main(){
    std::vector<std::vector<int>> testSet = {
        {1,1},
        {1,2,1},
        {4,3,2,1,4},
        {1,8,6,2,5,4,8,3,7}
    };

    for(std::vector<int> test : testSet){
        std::cout << "height = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == (test.size() - 1)? "}\n":",");
        }
        std::cout << "Max Area = " << maxArea(test) << std::endl << std::endl;
    }

    return 0;
}