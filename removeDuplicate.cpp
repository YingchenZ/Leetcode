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

// Before = {0,1,2,3,4,5,6,7,8,9}
// After = {0,1,2,3,4}

int main(){
    std::vector<int>test = {0,0,1,1,1,2,2,3,3,4};
    std::cout << "Before = {";
    for(int i = 0; i < test.size(); i++){
        std::cout << i << (i == (test.size() - 1)? "}\n":",");
    }
    removeDuplicates(test);
    std::cout << "After = {";
    for(int i = 0; i < test.size(); i++){
        std::cout << i << (i == (test.size() - 1)? "}\n":",");
    }

    return 0;
}