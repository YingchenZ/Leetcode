#include <stack>
#include <iostream>

// 0    *
// 1    /
// 2    +
// 3    -
int clumsy(int N) {
    
    int result = N;
    int sig = 0;

    std::stack<int> holder = {};
    N--;
    while(N > 0){
        if(sig == 0){ // *
            result =  result * N;
            sig++;
        }
        else if(sig == 1){ // /
            result = result / N;
            if(!holder.empty()){
                int top = holder.top();
                holder.pop();
                result = top - result;
            }
            sig++;
        }
        else if(sig == 2){    // +
            result = result + N;
            sig++;
        }
        else{       // -;
            holder.push(result);
            sig = 0;
            result = N;
        }
        N--;
    }
    
    if(!holder.empty()){
        int temp = holder.top();
        result = temp - result;
    }
    return result;
}

// Clumsy factorial for 4 = 7
// Clumsy factorial for 5 = 7
// Clumsy factorial for 6 = 8
// Clumsy factorial for 7 = 6
// Clumsy factorial for 8 = 9
// Clumsy factorial for 9 = 11
// Clumsy factorial for 10 = 12
// Clumsy factorial for 11 = 10
// Clumsy factorial for 10000 = 10001

int main(){
    int testSet[] = {4,5,6,7,8,9,10,11,10000};
    for(int test : testSet){
        std::cout << "Clumsy factorial for "<< test << " = "<<clumsy(test)<<std::endl;
    }
    return 0;
}