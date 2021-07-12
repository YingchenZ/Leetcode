#include <vector>
#include <iostream>

int hIndex(std::vector<int>& citations) {
    int left = 0, right = citations.size() - 1;
    int totalSize = citations.size();
    while(left <= right){
        int mid = (left + right) / 2;
        int noMoreThanH = totalSize - mid;

        if(citations[mid] >= noMoreThanH){
            right = mid - 1;
        }  
        else{
            left = mid + 1;
        } 
    }
    return totalSize - left;
}

void printArray(std::vector<int>& arr){
    std::cout << "citations = {";
    for(int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << ((i == arr.size() - 1)? "}":",");
    }
    std::cout << std::endl;
}

// citations = {1,2,100}
// H-Index = 2
// citations = {0,1,3,5,6}
// H-Index = 3

int main(){
    std::vector<std::vector<int>> testSet = {
        {1,2,100}, {0,1,3,5,6}
    };

    for(auto& test : testSet){
        printArray(test);
        std::cout << "H-Index = " << hIndex(test) << std::endl;
    }
    return 0;
}