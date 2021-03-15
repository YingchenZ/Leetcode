#include <vector>
#include <iostream>
std::vector<int> spiralOrder(std::vector<std::vector<int>> matrix) {
    int row = matrix.size(), col = matrix[0].size();
    int total = col * row;
    int visited = -999;
    int currentRow = 0, currentCol = 0, nextRow = 0, nextCol = 0;
    std::vector<int> result = {};
    // up       row + 1, col + 0
    // down     row - 1, col + 0
    // left     row + 0, col - 1
    // right    row + 0, col + 1
    // up, down, left, right 
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int moveToward = 3;
    for(int i = 0; i < total; i++){
    
        result.push_back(matrix[currentRow][currentCol]);
        matrix[currentRow][currentCol] = visited;
        
        // Determine the next block
        nextRow = currentRow + direction[moveToward][0];
        nextCol = currentCol + direction[moveToward][1];

        // change direction to up 0 when moveToward == 2 and (nextCol < 0 or nextBlock is visited)
        if(moveToward == 2 and (nextCol < 0 or matrix[nextRow][nextCol] == visited)){
            moveToward = 0;
        }
        // change direction to down 1 when moveToward == 3 and (nextCol >= col or nextBlock is visited)
        else if(moveToward == 3 and (nextCol >= col or matrix[nextRow][nextCol] == visited)){
            
            moveToward = 1;
        }
        // change direction to left 2 when moveToward == 1 and (nextRow >= row or nextBlock is visited)
        else if(moveToward == 1 and (nextRow >= row or matrix[nextRow][nextCol] == visited)){
            moveToward = 2;
        }
        // change direction to right 3 when moveToward == 0 and (nextRow < 0 or nextBlock is visited)
        else if(moveToward == 0 and (nextRow < 0 or matrix[nextRow][nextCol] == visited)){
            moveToward = 3;
        }

        currentRow += direction[moveToward][0];
        currentCol += direction[moveToward][1];
    }
    return result;
}

// Matrix is
//  1 2 3 4
//  5 6 7 8
//  9 10 11 12
// Spiral Matrix is
//  1 2 3 4 8 12 11 10 9 5 6 7
// Matrix is
//  1 2 3
//  4 5 6
//  7 8 9
// Spiral Matrix is
//  1 2 3 6 9 8 7 4 5

int main(){
    std::vector<int> answer = {};
    std::vector<std::vector<std::vector<int>>> testSet = {
                    {{1,2,3,4},{5,6,7,8},{9,10,11,12}}, 
                    {{1,2,3},{4,5,6},{7,8,9}}
                };
    for(std::vector<std::vector<int>> test : testSet){
        std::cout << "Matrix is"<< std::endl;
        for(int row = 0; row < test.size(); row++){
            for(int col = 0; col < test[row].size(); col++){
                std::cout << " " << test[row][col] ;
            }
            std::cout <<std::endl;
        }
        answer =   spiralOrder(test);
        std::cout << "Spiral Matrix is"<< std::endl;
        for(int num : answer){
            std::cout << " " << num;
        }
        std::cout <<std::endl;
    }
    
    return 0;
}
