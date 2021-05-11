#include <vector>
#include <iostream>

std::vector<int> decode(std::vector<int>& encoded) {
    int odd = 0;
    int even = 0;
    for(int i = 1; i <= encoded.size() +1; i++){
        odd ^= i;
    }
    for(int i = 1; i < encoded.size(); i+=2){
        even ^= encoded[i];
    }
    std::vector<int> ans = {odd ^ even};
    for(int i = 1; i < encoded.size() + 1; i++){
        ans.push_back(encoded[i - 1] ^ ans[i - 1]);
    }
    return ans;
}

// encoded = {3,1}
// decoded = {1,2,3}

// encoded = {6,5,4,6}
// decoded = {2,4,1,5,3}

int main(){
    std::vector<std::vector<int>> testSet = {
        {3,1}, {6,5,4,6}
    };
    for(std::vector<int> test : testSet){
        std::cout << "encoded = {";
        for(int i = 0; i < test.size(); i++){
            std::cout << test[i] << (i == (test.size() - 1)? "}\n":",");
        }
        std::vector<int> decoded = decode(test);
        std::cout << "decoded = {";
        for(int i = 0; i < decoded.size(); i++){
            std::cout << decoded[i] << (i == (decoded.size() - 1)? "}\n":",");
        }
        std::cout << std::endl;
    }
    return 0;
}