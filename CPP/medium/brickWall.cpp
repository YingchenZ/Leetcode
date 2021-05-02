#include <vector>
#include <unordered_map>
#include <iostream>

int leastBricks(std::vector<std::vector<int>>& wall) {
    // memorize the every gap's position
    std::unordered_map<int, int> gap = {};
    int row = wall.size();
    int maxGap = 0;

    for(int i = 0; i < row; i++){
        // indicate the gap position
        int currentP = 0;
        // Since we cannot cut the through the edge of the wall,
        // loop through the entire row except the last element
        for(int brick = 0; brick < wall[i].size() - 1; brick++){
            currentP += wall[i][brick];
            // increment the gap position by 1 to indicate a gap
            // shows up at the current position
            if(gap.count(currentP)){
                gap[currentP]++;
            }
            else{
                gap.insert({currentP, 1});
            }
            if(gap[currentP] > maxGap){
                maxGap =  gap[currentP];
            }
        }
    }
    // the answer should be cutting through the position with the most gap
    return row - maxGap;
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
//   1  1
//   2
//   1  1

// The Minimum Number of Crossed Bricks After Drawing a Vertical Line = 1
// ============ Test ============
//   1  2  2  1
//   3  1  2
//   1  3  2
//   2  4
//   3  1  2
//   1  3  1  1

// The Minimum Number of Crossed Bricks After Drawing a Vertical Line = 2

int main(){
    std::vector<std::vector<std::vector<int>>> testSet = {
        {
            {1,1},
            {2},
            {1,1}
        },
        {
            {1,2,2,1},
            {3,1,2},
            {1,3,2},
            {2,4},
            {3,1,2},
            {1,3,1,1}
        }
    };
    for(auto test : testSet){
        std::cout << "============ Test ============" << std::endl;
        printMatrix(test);
        std::cout << "The Minimum Number of Crossed Bricks After Drawing a Vertical Line = "<< leastBricks(test) <<std::endl;
    }
    return 0;
}