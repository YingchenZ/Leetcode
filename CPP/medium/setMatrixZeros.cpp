#include <vector>
#include <iostream>

void setZeroes(std::vector<std::vector<int>>& matrix) {
    int row = matrix.size(), col = matrix[0].size();
    bool firstRowZero = false;
    // check to see if the first row contains zero
    for(int i = 0; i < col; i++){
        if(matrix[0][i] == 0){
            firstRowZero = true;
            break;
        }
    }

    // check every block in the maxtrix (not include the first row)
    // if the block (i, j) is zero
    //      set matrix[i][0] = 0    => indicate this row needs to be zeroed
    //      set matrix[0][j] = 0    => indicate this col needs to be zeroed
    for(int i = 1; i < row; i++){
        for(int j = 0; j < col; j++){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    // check every block in the first column
    // if zero, then zero out the entire row
    for(int i = 1; i < row; i++){
        if(matrix[i][0] == 0){
            for(int j = 0; j < col; j++){
                matrix[i][j] = 0;
            }
        }
    }

    // check every block in the first row
    // if zero, then zero out the entire col
    for(int i = 0; i < col; i++){
        if(matrix[0][i] == 0){
            for(int j = 0; j < row; j++){
                matrix[j][i] = 0;
            }
        }
    }

    // zero out the first row if a zero shows up in the first row
    if(firstRowZero){
        for(int i = 0; i < col; i++){
            matrix[0][i] = 0;
        }
    }
}

void printMatrix(std::vector<std::vector<int>> matrix){
    for(int row = 0; row < matrix.size(); row++){
        for(int col = 0; col < matrix[row].size(); col++){
            std::cout << (matrix[row][col] < 10?" ":"") << " " << matrix[row][col] ;
        }
        std::cout <<std::endl;
    }
    std::cout << std::endl;
}

// ============ Test ============
//   Before
//   1  1  1
//   1  0  1
//   1  1  1

//   After
//   1  0  1
//   0  0  0
//   1  0  1

// ============ Test ============
//   Before
//   0  1  2  0
//   3  4  5  2
//   1  3  1  5

//   After
//   0  0  0  0
//   0  4  5  0
//   0  3  1  0

int main(){
    std::vector<std::vector<std::vector<int>>> testSet = {
        {
            {1,1,1},
            {1,0,1},
            {1,1,1}
        },
        {
            {0,1,2,0},
            {3,4,5,2},
            {1,3,1,5}
        }
    };

    for(auto test : testSet){
        std::cout << "============ Test ============" << std::endl;
        std::cout << "  Before"<<std::endl;
        printMatrix(test);
        setZeroes(test);
        std::cout << "  After"<<std::endl;
        printMatrix(test);
    }
    return 0;
}