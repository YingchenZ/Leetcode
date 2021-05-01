#include <vector>
#include <iostream>

int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int X) {
    if(customers.size() == 1) return customers[0];
    int ans = 0;
    int maxBoost = 0;
    for(int i = 0; i < customers.size(); i++){
        if(grumpy[i] == 0){
            ans += customers[i];
        }
        else{
            if(i < X){
                maxBoost += customers[i];
            }
        }
    }

    int currentBoost = maxBoost;
    for(int i = 1, j = X; i < customers.size() - (X - 1) && j < customers.size(); i++, j++){
        if(grumpy[i - 1] == 1){
            currentBoost -= customers[i - 1];
        }
        if(grumpy[j] == 1){
            currentBoost += customers[j];
        }

        if(maxBoost < currentBoost){
            maxBoost = currentBoost;
        }
    }
    
    return maxBoost + ans;
}

void printVector(std::vector<int> vec){
    std::cout << "{";
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << (i == (vec.size() - 1)?"}":",");
    }
    std::cout << std::endl;
}

// customers = {1,0,1,2,1,1,7,5}
// grumpy = {0,1,0,1,0,1,0,1}
// X = 3
// Maximum Number of Customers That Can Be Satisfied Throughout The Day = 16

int main(){
    std::vector<int> customers = {1,0,1,2,1,1,7,5};
    std::vector<int> grumpy = {0,1,0,1,0,1,0,1};
    int X = 3;

    std::cout << "customers = ";
    printVector(customers);

    std::cout << "grumpy = ";
    printVector(grumpy);
    std::cout << "X = "<< X << std::endl;
    std::cout << "Maximum Number of Customers That Can Be Satisfied Throughout The Day = " <<maxSatisfied(customers, grumpy, X)<< std::endl; 
    return 0;
}