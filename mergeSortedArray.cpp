#include <algorithm>
#include <vector>
#include <iostream>
void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    for(int i = 0; i < n; i++){
        nums1[m + i] = nums2[i];
    }
    std::sort(nums1.begin(), nums1.end());
}

// nums1 = {1,2,3,0,0,0}
// nums2 = {2,5,6}
// After merged nums1 = {1,2,2,3,5,6}

int main(){
    std::vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    std::vector<int> nums2 = {2,5,6};
    int n = 3;
    std::cout <<"nums1 = {";
    for(int i = 0; i < nums1.size(); i++){
        std::cout << nums1[i] << (i == (nums1.size() - 1)? "}": ",");
    }
    std::cout <<"\nnums2 = {";
    for(int i = 0; i < nums2.size(); i++){
        std::cout << nums2[i] << (i == (nums2.size() - 1)? "}": ",");
    }

    std::cout <<"\nAfter merged nums1 = {";
    merge( nums1, m, nums2, n);
    for(int i = 0; i < nums1.size(); i++){
        std::cout << nums1[i] << (i == (nums1.size() - 1)? "}": ",");
    }
    return 0;
}