#include <vector>
#include <iostream>

void printMatrix(std::vector<std::vector<int>>& matrix){
    for(int row = 0; row < matrix.size(); row++){
        for(int col = 0; col < matrix.size(); col++){
            std::cout << matrix[row][col] << (col == matrix.size() -1 ?"\n":" ");
        }
    }
}

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int m = matrix.size() - 1, n = matrix[0].size();
    int row = matrix.size() - 1, col = 0;

    while(row >= 0 && col < n){
        if(matrix[row][col] == target){
            return true;
        }
        else if(matrix[row][col] < target){
            // current block < target
            // it means the target may in this row
            // hence we should go right and try to find the target
            col++;
        }  
        else{
            // current block > target
            // if the current block > target
            // then our target is less than the rest of the row
            // hence we need to go up
            row--;
        }
    }
    return false;
}

struct TestHolder{
    std::vector<std::vector<int>> vec;
    int target;
    TestHolder(std::vector<std::vector<int>> vec, int target):vec(vec), target(target){}
};

// Target = 5
// 1 4 7 11
// 3 6 9 16
// 10 13 14 17
// 18 21 23 26
// Not Found

// Target = 20
// 1 4 7 11
// 3 6 9 16
// 10 13 14 17
// 18 21 23 26
// Not Found

int main(){
    std::vector<TestHolder*> testSet = {
        new TestHolder{{{1,4,7,11,15},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}}, 5},
        new TestHolder{{{1,4,7,11,15},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}}, 20}
    };

    for(auto& test : testSet){
        std::cout <<"Target = " << test->target << std::endl;
        printMatrix(test->vec);
        std::cout << (searchMatrix(test->vec, test->target)? "Found" :"Not Found") << std::endl; 
        
        std::cout << std::endl;
    }

    return 0;
}