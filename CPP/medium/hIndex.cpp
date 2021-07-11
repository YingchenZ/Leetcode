#include <vector>
#include <iostream>

int hIndex(std::vector<int>& citations) {
    int maxCite = 0;
    for(auto& n : citations){
        maxCite = std::max(maxCite, n);
    }

    std::vector<int> counting(maxCite + 1);
    for(auto& n : citations){
        counting[n]++;
    }

    std::vector<int> total(maxCite + 1);
    for(int i = 0; i < total.size(); i++){
        total[i] = counting[i];
        if(i > 0){
            total[i] += total[i - 1];
        }
    }
    int totalP = citations.size();
    for(int h = total.size() - 1; h >= 0; h--){
        int atLeastH = totalP - total[h] + counting[h];
        if(atLeastH >= h){
            return h;
        }
    }

    return 0;
}

void printArray(std::vector<int>& arr){
    std::cout << "citations = {";
    for(int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << ((i == arr.size() - 1)? "}":",");
    }
    std::cout << std::endl;
}

// citations = {1,3,1}
// H-Index = 1
// citations = {3,0,6,1,5}
// H-Index = 3

int main(){
    std::vector<std::vector<int>> testSet = {
        {1,3,1}, {3,0,6,1,5}
    };

    for(auto& test : testSet){
        printArray(test);
        std::cout << "H-Index = " << hIndex(test) << std::endl;
    }
    return 0;
}