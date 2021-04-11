#include <unordered_set>
#include <queue>
#include <iostream>

int nthUglyNumber(int n) {
    if(n <= 6) return n;
    std::priority_queue<long, std::vector<long>, std::greater<long>> minHeap = {};
    std::unordered_set<long> existed = {};
    // int counter = 1;
    long start = 1;
    minHeap.push(start);
    // existed.insert(start);
    while(existed.size() < n){
        start = minHeap.top();
        
        minHeap.pop();
        if(existed.count(start) == 0){
            
            existed.insert(start);
            // std::cout << start << " + "<< existed.size() << std::endl;
        }
        else{
            continue;
        }
    

        minHeap.push(start * 2);
        minHeap.push(start * 3);
        minHeap.push(start * 5);

        // std::cout << "Counter = "<< counter << std::endl;

    }
    return start;

}

// The 1th ungly number = 1
// The 10th ungly number = 12
// The 12th ungly number = 16

int main(){
    int testSet[] = {1,10,12};

    for(int test : testSet){
        std::cout << "The "<< test <<"th ungly number = "<< nthUglyNumber(test)<< std::endl;
    }
    return 0;
}