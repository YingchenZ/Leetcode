#include <iostream>
#include <vector>
std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> ans;

    ans.push_back({1});
    if(numRows == 1) return ans;
    ans.push_back({1,1});
    if(numRows == 2) return ans;
    
    for(int i = 2; i < numRows; i++){
        int rowSize = i + 1;
        std::vector<int> thisRow(rowSize, 1);
        for(int block = 1; block < rowSize - 1; block++){
            thisRow[block] = ans[i - 1][block - 1] + ans[i - 1][block];
        }
        ans.push_back(thisRow);
    }
    return ans;
}


// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1

int main(){
    std::vector<std::vector<int>> triangle = generate(5);
    for(std::vector<int> row: triangle){
        for(int num : row){
            std::cout << num <<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}