#include <vector>
#include <iostream>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    if(nums1.size() > nums2.size()){
        std::vector<int>& temp = nums1;
        nums1 = nums2;
        nums2 = temp;
    }

    int start = 0, end = nums1.size(), totalLength = nums1.size() + nums2.size();

    while(start <= end){
        int partionX = (start + end) / 2;
        int partionY = (totalLength + 1) / 2 - partionX;

        double maxLeftX = partionX == 0 ? -std::numeric_limits<double>::infinity() : nums1[partionX - 1];          
        double maxLeftY = partionY == 0 ? -std::numeric_limits<double>::infinity() : nums2[partionY - 1];

        double minRightX = partionX == nums1.size()? std::numeric_limits<double>::infinity() : nums1[partionX];
        double minRightY = partionY == nums2.size()? std::numeric_limits<double>::infinity() : nums2[partionY];

        if(maxLeftY <= minRightX && maxLeftX <= minRightY ) {
            if(totalLength % 2 == 0)
                return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
            return std::max(maxLeftX, maxLeftY) * 1.0;
        }
        else if(maxLeftY > minRightX){
            start = partionX + 1;
        }
        else{
            end = partionX - 1;
        }
    }

    return -1.0;
}

int main(int argc, char **argv){
    std::cout<<"The median of {1,3} and {2} = "<<findMedianSortedArrays({1,3},{2})<<std::endl;
}