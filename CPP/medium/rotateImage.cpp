#include <iostream>
#include <vector>

void rotate(std::vector<std::vector<int>>& matrix) {
    int N = matrix.size();
    

    for(int row = 0; row < N; row++){
        for(int col = row + 1; col < N; col++){
            std::swap(matrix[row][col], matrix[col][row]);
        }
    }

    for(int row = 0; row < N; row++){
        for(int head = 0, tail = N - 1; head < tail; head++, tail--){
            std::swap(matrix[row][head], matrix[row][tail]);
        }
    }
}

void printMatrix(std::vector<std::vector<int>>& matrix){
    for(int row = 0; row < matrix.size(); row++){
        for(int col = 0; col < matrix.size(); col++){
            std::cout << matrix[row][col] << (col == matrix.size() -1 ?"\n":" ");
        }
    }
}

// ===== Before =====
// 1 2 3
// 4 5 6
// 7 8 9
// ===== After =====
// 7 4 1
// 8 5 2
// 9 6 3

// ===== Before =====
// 5 1 9 11
// 2 4 8 10
// 13 3 6 7
// 15 14 12 16
// ===== After =====
// 15 13 2 5
// 14 3 4 1
// 12 6 8 9
// 16 7 10 11

int main(){
    std::vector<std::vector<std::vector<int>>> testSet = {
        {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        },
        {
            {5,1,9,11},
            {2,4,8,10},
            {13,3,6,7},
            {15,14,12,16}
        }
    };

    for(auto& test : testSet){
        std::cout << "===== Before =====" << std::endl;
        printMatrix(test);
        rotate(test);
        std::cout << "===== After =====" << std::endl;
        printMatrix(test);
        std::cout << std::endl;
    }

    return 0;
}