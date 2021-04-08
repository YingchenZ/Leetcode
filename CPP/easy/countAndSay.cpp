#include <string>
#include <iostream>

std::string countAndSay(int n) {    
    if(n == 1) return "1";
    std::string before = countAndSay(n - 1);
    
    std::string answer = "";
    if(before.size() == 1) return "11";

    int current = 0;

    int count = 1;
    for(int i = 1; i < before.size(); i++){
        if(before[i] != before[current]){
            std::string num = std::to_string(count);
            answer += num + before[current];
            current = i;
            count = 1;
        }
        else{
            count++;
        }
    }
    return answer + std::to_string(count) + before[current];
}

// N = 1 say 1
// N = 5 say 111221
// N = 8 say 1113213211

int main(){
    int testSet[] = {1,5,8};

    for(int test : testSet){
        std::cout << "N = "<< test << " say "<<countAndSay(test)<< std::endl;
    }
    return 0;
}