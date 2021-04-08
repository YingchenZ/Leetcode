#include <vector>
#include <iostream>
bool searchMatrix(std::vector<std::vector<int>> matrix, int target) {
    if(target < matrix[0][0]) return false;
    int row = matrix.size(), col = matrix[row - 1].size() - 1;
    if(target > matrix[row - 1][col]) return false;
    int potentialRow = -1;


    for(int i = 0; i < row; i++){
        int rowMin = matrix[i][0], rowMax = matrix[i][col];
        if(target >= rowMin && target <= rowMax){
            potentialRow = i;
            break;
        }
    }
    

    if(potentialRow != -1){
        if(matrix[potentialRow].size() == 1){
            return matrix[potentialRow][0] == target;
        }
        int left = 0, right = col, mid = 0;
        while(left <= right){
            mid = (right + left) / 2;
            if(matrix[potentialRow][mid] == target){
                return true;
            }
            if(target > matrix[potentialRow][mid]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }
    return false;
}

// ========= Test =========
//  1  3  5  7
// 10 11 16 20
// 23 30 34 60

// Target = 3 is found.
// Target = 13 is not found.

int main(){
    std::vector<std::vector<int>> test = {{1,3,5,7},{10,11,16,20},{23,30,34,60}}; 
    std::cout << "========= Test =========" << std::endl;
    for(std::vector<int> row : test){
        for(int col : row){
            std::cout << ((col < 10)? " ":"")<< col << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    int target[] = {3,13};
    for(int i : target){
        std::cout << "Target = "<< i << " is "<< (searchMatrix(test, i)? "found." : "not found.") << std::endl;
    }
    return 0;
}