#include <string>
#include <utility>
#include <vector>
#include <iostream>

int strStr(std::string haystack, std::string needle) {
    if(haystack.size() < needle.size()) return -1;
    if(needle == "") return 0;
    if(haystack == "") return - 1;
    

    for(int i = 0; i < haystack.size(); i++){
        bool equal = true;
        for(int j = 0; j < needle.size(); j++){
            if(haystack[(i + j) >= haystack.size()? i : (i + j)] != needle[j]){
                equal = false;
                break;
            }
        }
        if(equal) return i;
        if(haystack.size()- i < needle.size()) return -1;
    }
    return -1;
}

// haystack = ""   needle = ""     start at index = 0
// haystack = "hello"      needle = "ll"   start at index = 2
// haystack = "aaaaa"      needle = "bba"  start at index = -1
// haystack = "mississippi"        needle = "ippia"        start at index = -1

int main(){
    std::vector<std::pair<std::string, std::string>> testSet = {
        {"",""},
        {"hello","ll"},
        { "aaaaa", "bba"},
        {"mississippi", "ippia"} 
    };

    for(auto test : testSet){
        std::cout << "haystack = \"" << test.first << "\"\tneedle = \""<<test.second<<"\""<< "\tstart at index = "<< strStr(test.first, test.second)<< std::endl;
    }

    return 0;
}