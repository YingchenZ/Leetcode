#include <vector>
#include <utility>
#include <iostream>

bool canBloom(std::vector<int> bloomDay, int demand, int day, int k){
    int bouquet = 0;
    int flower = 0;
    for(int bday : bloomDay){
        // if the bloomDay[i] > the given day, it's not what we need (the flower is not bloomed and cannot be used to make a bouquet)
        // we set flower number to zero to indicate that we start a new one
        if(bday > day){
            flower = 0;
            continue;
        } 
        flower++;
        // if numbers of flower == k
        if(flower == k){
            // start a new one
            flower = 0;
            // increment by 1
            bouquet++;
            // if the number of bouquet meets the demand, return true
            if(bouquet == demand) return true;
        }
    }
    return false;
}

int minDays(std::vector<int>& bloomDay, int m, int k) {
    if(m > (bloomDay.size() / k)) return -1;
    int low = 1000000000 , high = 1;

    for(int day :bloomDay){
        low = std::min(low, day);
        high = std::max(high, day);
    }

    int mid = 0;
    while(low <= high){
        mid = (low + high) / 2 ;
        // if the current mid can make a bouquet
        // we should spend less time
        if(canBloom(bloomDay, m, mid, k)){
            high = mid - 1;
        }
        else{
            // since the current numbers of day cannot make a bouquet
            // we need more time
            low = mid + 1;
        }
    }

    return low;
}

struct TestHolder{
    std::vector<int> bloomDay;
    int m;
    int k;
    TestHolder(std::vector<int> day, int need, int num) : bloomDay(day), m(need), k(num){};
};

// bloomDay = {1,10,3,10,2}        m = 3   k = 1
// The Minimum Number of Days = 3

// bloomDay = {1,10,3,10,2}        m = 3   k = 2
// The Minimum Number of Days = -1

// bloomDay = {7,7,7,7,12,7,7}     m = 2   k = 3
// The Minimum Number of Days = 12

// bloomDay = {1000000000,1000000000}      m = 1   k = 1
// The Minimum Number of Days = 1000000000

// bloomDay = {1,10,2,9,3,8,4,7,5,6}       m = 4   k = 2
// The Minimum Number of Days = 9

int main(){
    std::vector<TestHolder*> testSet = {
        new TestHolder({1,10,3,10,2},3,1),
        new TestHolder({1,10,3,10,2},3,2),
        new TestHolder({7,7,7,7,12,7,7},2,3),
        new TestHolder({1000000000,1000000000},1,1),
        new TestHolder({1,10,2,9,3,8,4,7,5,6},4,2)
    };

    for(TestHolder* test : testSet){
        std::cout << "bloomDay = {";
        for(int i = 0; i < test->bloomDay.size(); i++){
            std::cout << test->bloomDay[i] << (i == test->bloomDay.size() - 1? "}\t":",");
        }
        std::cout << "m = "<< test->m << "\tk = "<< test->k<<std::endl;
        std::cout <<"The Minimum Number of Days = " << minDays(test->bloomDay, test->m, test->k) << std::endl << std::endl;
    }

    return 0;
}