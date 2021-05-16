#include <vector>
#include <algorithm>
#include <iostream>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    if(intervals.size() <= 1)
        return intervals;
    std::sort(intervals.begin(), intervals.end());
    
    std::vector<std::vector<int>> ans = {};
    ans.push_back(intervals[0]);
    int start = intervals[0][0];
    int end = intervals[0][1];
    
    for(int i = 1; i < intervals.size(); i++){
        // start    interval[i][0]  end ....
        if(intervals[i][0] >= start && intervals[i][0] <= end){
            // update the end if the interval[i][1] > end
            ans[ans.size() - 1][1] = std::max(intervals[i][1], end);
            end = ans[ans.size() - 1][1];
        }
        else if(end < intervals[i][0]){
            // start  end interval[i][0] ....
            // update both start and end
            start = intervals[i][0];
            end = intervals[i][1];
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}

void print2D(std::vector<std::vector<int>> arr){
    for(int i = 0; i < arr.size(); i++){
        std::cout << "{";
        if(arr[i].size() == 0){
            std::cout << "}";
        }
        for(int j = 0; j < arr[i].size(); j++){

            std::cout << arr[i][j] << (j == arr[i].size() - 1? "}":",");
        }
        std::cout << (i == arr.size() - 1? "}\n":", ");
    }
}

// Intervals = {6,8}, {1,9}, {2,4}, {4,7}}
// Merged Intervals = {1,9}}

// Intervals = {1,4}, {0,2}, {3,5}}
// Merged Intervals = {0,5}}

// Intervals = {1,4}, {4,5}}
// Merged Intervals = {1,5}}

// Intervals = {1,3}, {2,6}, {8,10}, {15,18}}
// Merged Intervals = {1,6}, {8,10}, {15,18}}

int main(){
    std::vector<std::vector<std::vector<int>>> testSet = {
        {{6,8}, {1,9 }, {2,4 }, {4,7}},
        {{1,4},{0,2},{3,5}},
        {{1,4}, {4,5}},
        {{1,3},{2,6},{8,10},{15,18}}
    };

    for(std::vector<std::vector<int>> test : testSet){
        std::cout << "Intervals = ";
        print2D(test);
        std::vector<std::vector<int>> ans = merge(test);
        std::cout << "Merged Intervals = ";
        print2D(ans);
        std::cout << std::endl;
    }

    return 0;
}