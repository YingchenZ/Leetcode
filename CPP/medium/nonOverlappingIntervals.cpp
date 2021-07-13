#include <vector>
#include <algorithm>
#include <iostream>

int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
    if(intervals.size() == 1)   return 0;
    std::sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
        return u[1] < v[1];
    });

    int keep = 1;
    int start = intervals[0][0], end = intervals[0][1];
    for(int i = 1; i < intervals.size(); i++){
        // if we want to avoid overlapping while keeping intervals as much as possible
        // we should find the interval that start after the previous end
        // the next interval starts right after the previous's end is idea
        // otherwise, we find the one starts after the previous to avoid overlap
        if(intervals[i][0] >= end){
            start = intervals[i][0];
            end = intervals[i][1];
            keep++;
        }
    }
    return intervals.size() - keep;
}   

void printMatrix(std::vector<std::vector<int>>& matrix){
    std::cout << "{";
    for(int row = 0; row < matrix.size(); row++){
        std::cout << "{" << matrix[row][0] << ","<<matrix[row][1] << "}";
        if(row != matrix.size() - 1){
            std::cout << ", ";
        }
        
    }
    std::cout << "}" << std::endl;
}

// intervals = {{1,2}, {2,3}}
// Min Num of Intervals I should remove = 0

// intervals = {{1,2}, {1,2}, {1,2}}
// Min Num of Intervals I should remove = 2

// intervals = {{1,2}, {2,3}, {3,4}, {1,3}}
// Min Num of Intervals I should remove = 1

int main(){
    std::vector<std::vector<std::vector<int>>> testSet ={
        {{1,2},{2,3}},
        {{1,2},{1,2},{1,2}},
        {{1,2},{2,3},{3,4},{1,3}}
    };

    for(auto& test : testSet){
        std::cout << "intervals = ";
        printMatrix(test);
        std::cout << "Min Num of Intervals I should remove = " << eraseOverlapIntervals(test) << std::endl << std::endl;
    }

    return 0;
}