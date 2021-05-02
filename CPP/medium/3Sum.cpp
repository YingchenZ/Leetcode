#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int> nums) {
    std::vector<std::vector<int>> result = std::vector<std::vector<int>>{};
    int sizeOfList = nums.size();
    if(sizeOfList < 3){
        return result;
    }

    std::sort(nums.begin(),nums.end());

    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1, right = nums.size() - 1;
        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if(sum > 0){
                right--;
            }
            else if (sum < 0){
                left++;
            }
            else{
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                while(left < right && nums[left] == nums[left - 1]){
                    left++;
                }
            }
        }
    }
    
    return result;
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

// Test = {-1, 0, 1, 2, -1, -4}
// Result = {-1, -1, 2}, {-1, 0, 1}

// Test = {1, -1, -1, 0}
// Result = {-1, 0, 1}

// Test = {}
// Result = {}

// Test = {0}
// Result = {}

// Test = {1, 2, 3, 4, 5, -3}
// Result = {-3, 1, 2}

// Test = {0, 0, 0, 0, 0, 0}
// Result = {0, 0, 0}

int main(){
    for(auto test : std::vector<std::vector<int>>{{-1,0,1,2,-1,-4}, {1,-1,-1,0}, {}, {0}, {1,2,3,4,5,-3}, {0,0,0, 0,0,0}}){
        std::cout<< "Test = {";
        for(int j = 0; j < test.size(); j++){
            std::cout << test[j] << (j == (test.size() - 1)?"":", ") ;
        }
        std::cout<<"}"<<std::endl;
        std::vector<std::vector<int>> result= threeSum(test);
        std::cout << "Result = ";
        printMatrix(result);
        std::cout << std::endl;
    }
    
    return 0;
}