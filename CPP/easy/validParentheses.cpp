#include <stack>
#include <iostream>
#include <vector>
#include <string>


bool isValid(std::string s) {
    std::stack<char> bracket = {};

    for(auto c : s){
        if(c == '(')        bracket.push(')');
        else if(c == '{')   bracket.push('}');
        else if(c == '[')   bracket.push(']');
        else{
            if(bracket.empty() || c != bracket.top()) return false;
            bracket.pop();
        }
    }
    return bracket.empty();
}

// Test () is valid
// Test ()[]{} is valid
// Test (] is invalid
// Test ([)] is invalid
// Test {[]} is valid
// Test ] is invalid

int main(){
    std::vector<std::string> testSet = {
        "()","()[]{}","(]","([)]","{[]}","]"
    };
    for(std::string test : testSet){
        std::cout << "Test "<< test << " is ";
        std::cout << (isValid(test)? "valid" : "invalid")<< std::endl;
    }

    return 0;
}