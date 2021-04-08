#include <iostream>
#include <vector>

std::vector<int> getRow(int rowIndex) {
    if(rowIndex == 0){
        return std::vector<int>{1};
    }
    if(rowIndex == 1){
        return std::vector<int>{1,1};
    }
    std::vector<int> previous = {1,1};
    std::vector<int> current = {};
    for(int i = 3; i <= rowIndex + 1; i++){
        current = {};
        current.push_back(1);

        for(int j = 1; j < i - 1; j++){
            current.push_back(previous[j -1]+ previous[j]);
        }

        current.push_back(1);
        previous = current;
        
    }
    return current;
}

// 1 20 190 1140 4845 15504 38760 77520 125970 167960 184756 167960 125970 77520 38760 15504 4845 1140 190 20 1


int main(){
    std::vector<int> ans = getRow(20);
    for(int num: ans){
        std::cout << num <<" ";
    }
    return 0;
}