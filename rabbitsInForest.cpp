#include <vector>
#include <iostream>

int numRabbits(std::vector<int>& answers) {
    std::vector<int> tracking(1000, 0);

    int small = 0;
    for(int num : answers){
        if(tracking[num] == 0){
            tracking[num] = num;
            small += num + 1;
        }
        else{
            tracking[num]--;
        }
    }
    return small;
}

// Test = [1,0,1,0,0]
// Min Number of Rabbits = 5
// Test = [1,1,2]
// Min Number of Rabbits = 5
// Test = [10,10,10]
// Min Number of Rabbits = 11
// Test = [0,0,1,1,1]
// Min Number of Rabbits = 6

int main(){
    std::vector<std::vector<int>> testSet = {
        {1,0,1,0,0}, {1,1,2}, {10,10,10},{0,0,1,1,1}
    };
    for(std::vector<int> test : testSet){
        std::cout << "Test = [";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == (test.size() - 1)? "]\n": ",");
        }
        std::cout << "Min Number of Rabbits = "<< numRabbits(test) << std::endl;
    }
    return 0;
}