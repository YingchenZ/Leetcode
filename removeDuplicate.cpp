#include <vector>
#include <iostream>

int removeDuplicates(std::vector<int>& nums) {
    for (auto itor = nums.begin(); itor != nums.end(); itor++){
        if(itor == nums.begin()){
            continue;
        }
        if(*itor == *(itor - 1)){
            itor = nums.erase(itor-1);
        }
    }
    return nums.size();
}

// Before = {1,1,1,2,2,3}
// After  = {1,2,3}

// Before = {1,1}
// After  = {1}

// Before = {1,2,3}
// After  = {1,2,3}

// Before = {0,0,1,1,1,1,2,3,3}
// After  = {0,1,2,3}

int main(){
    std::vector<std::vector<int>> testSet = {
        {1,1,1,2,2,3}, {1,1},{1,2,3},{0,0,1,1,1,1,2,3,3}
    };

    for(std::vector<int> test : testSet){
        std::cout << "Before = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == (test.size() - 1)? "}\n":",");
        }
        removeDuplicates(test);
        std::cout << "After  = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i]  << (i == (test.size() - 1)? "}\n\n":",");
        }
    }

    return 0;
}
