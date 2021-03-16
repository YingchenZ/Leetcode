#include <vector>
#include <iostream>

std::vector<std::vector<int>> generateMatrix(int n) {
    if(n == 0){
        return {};
    }
    int visited = 0;
    int row = n, col = n;
    int numberSet = n * n, theNumber = -1;
    std::vector<int> inner(n, 0);
    std::vector<std::vector<int>> result (n, inner);
    // up       row + 1, col + 0
    // down     row - 1, col + 0
    // left     row + 0, col - 1
    // right    row + 0, col + 1
    // up, down, left, right 
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int moveToward = 3;
    int currentRow = 0, currentCol = 0, nextRow = 0, nextCol = 0;

    for(int i = 0; i < numberSet; i++){
        theNumber = i + 1;

        result[currentRow][currentCol] = theNumber;
        // matrix[currentRow][currentCol] = visited;
        
        // Determine the next block
        nextRow = currentRow + direction[moveToward][0];
        nextCol = currentCol + direction[moveToward][1];

        // change direction to up 0 when moveToward == 2 and (nextCol < 0 or nextBlock is visited)
        if(moveToward == 2 and (nextCol < 0 or result[nextRow][nextCol] != 0)){
            moveToward = 0;
        }
        // change direction to down 1 when moveToward == 3 and (nextCol >= col or nextBlock is visited)
        else if(moveToward == 3 and (nextCol >= col or result[nextRow][nextCol] != 0)){
            
            moveToward = 1;
        }
        // change direction to left 2 when moveToward == 1 and (nextRow >= row or nextBlock is visited)
        else if(moveToward == 1 and (nextRow >= row or result[nextRow][nextCol] != 0)){
            moveToward = 2;
        }
        // change direction to right 3 when moveToward == 0 and (nextRow < 0 or nextBlock is visited)
        else if(moveToward == 0 and (nextRow < 0 or result[nextRow][nextCol] != 0)){
            moveToward = 3;
        }
        currentRow += direction[moveToward][0];
        currentCol += direction[moveToward][1];
    }
    return result;
}

// The matrix size = 2
// Spiral Matrix is
//   1  2
//   4  3

// The matrix size = 3
// Spiral Matrix is
//   1  2  3
//   8  9  4
//   7  6  5

// The matrix size = 4
// Spiral Matrix is
//   1  2  3  4
//  12 13 14  5
//  11 16 15  6
//  10  9  8  7

// The matrix size = 5
// Spiral Matrix is
//   1  2  3  4  5
//  16 17 18 19  6
//  15 24 25 20  7
//  14 23 22 21  8
//  13 12 11 10  9

int main(){
    std::vector<std::vector<int>> answer = {};
    std::vector<int> testSet = {2, 3, 4, 5};
    for(int size : testSet){
        std::cout << "The matrix size = "<< size << std::endl;

        answer = generateMatrix(size);
        std::cout << "Spiral Matrix is"<< std::endl;
        for(int row = 0; row < answer.size(); row++){
            for(int col = 0; col < answer[row].size(); col++){
                std::cout << (answer[row][col] < 10?" ":"") << " " << answer[row][col] ;
            }
            std::cout <<std::endl;
        }
        std::cout <<std::endl;
    }
    
    return 0;
}