#include <vector>
#include <string>
#include <stack>
#include <iostream>

int isSig(std::string str){
    
    if(str == "+"){
        return 1;
    }
    else if (str == "-"){
        return 2;
    }
    else if (str == "*"){
        return 3;
    }
    else if (str == "/"){
        return 4;
    }
    else{
        return -1;
    }
}

int evalRPN(std::vector<std::string>& tokens) {
    if(tokens.size() == 0) return 0;
    if(tokens.size() == 1) return stoi(tokens[0]);

    int firstNum = -999, secondNum = -999;
    std::stack<int> rpnStack = {};
    int operand = 999;
    for(std::string str : tokens){
        if((operand = isSig(str)) != -1 && rpnStack.size() >= 2){
            secondNum = rpnStack.top();
            rpnStack.pop();
            firstNum = rpnStack.top();
            rpnStack.pop();
            switch( operand){
                case 1:
                    rpnStack.push(firstNum + secondNum);
                    break;
                case 2:
                    rpnStack.push(firstNum - secondNum);
                    break;
                case 3:
                    rpnStack.push(firstNum * secondNum);
                    break;
                case 4:
                    rpnStack.push(firstNum / secondNum);
                    break;
                default:
                    continue;
            }
        }
        else if((operand = isSig(str)) == -1){
            rpnStack.push(stoi(str));
        }
        else{
            continue;
        }
    }

    return firstNum == -999? -999999 : rpnStack.top();
}

// Current test = 10 6 9 3 + -11 * / * 17 + 5 +
// Ans = 22
// Current test = 4 13 5 / +
// Ans = 6
// Current test = 2 1 + 3 *
// Ans = 9

int main(){
    std::vector<std::vector<std::string>> testSet = {
        {"10","6","9","3","+","-11","*","/","*","17","+","5","+"},
        {"4","13","5","/","+"},
        {"2","1","+","3","*"}
    };
    for(auto test: testSet){
        std::cout << "Current test =";
        for(auto operand : test){
            std::cout << " " << operand;
        }
        std::cout << "\nAns = " << evalRPN(test) << std::endl;
    }
    
    return 0;
}