#include <vector>
#include <iostream>

class Solution {
private:
    int bad = -1;
public:
    Solution(int bad) : bad(bad){}

    bool isBadVersion(int num){
        return num >= bad;
    }

    int firstBadVersion(int n) {
        long long left = 1, right = n;
        long long mid = 0;
        while(left <= right){
            mid = (left + right) / 2;
            if(isBadVersion(mid)){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
        return left;
    }
};

// n = 5   First Bad Version = 4
// n = 1   First Bad Version = 1
// n = 18  First Bad Version = 6
// n = 1705930310  First Bad Version = 1508243771

int main(){
    std::vector<std::vector<int>> testSet = {
        {5,4},{1,1},{18,6}, {1705930310,1508243771}
    };

    for(std::vector<int> test : testSet){
        Solution* sol = new Solution(test[1]);
        std::cout << "n = " << test[0] <<"\tFirst Bad Version = " << sol->firstBadVersion(test[0]) << std::endl;
    }
    return 0;
}