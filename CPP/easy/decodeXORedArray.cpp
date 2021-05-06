#include <vector>
#include <iostream>

std::vector<int> decode(std::vector<int>& encoded, int first) {
    std::vector<int> ans(encoded.size() + 1, 0);
    ans[0] = first;

    for(int i = 1; i < ans.size(); i++){
        ans[i] = (ans[i - 1] ^ encoded[i - 1]);
    }
    return ans;
}

class TestHolder{
public:
    std::vector<int> encoded;
    int first;
    TestHolder(std::vector<int> arr, int num) : encoded(arr), first(num){}
};

// encoded = {1,2,3}       first = 1
// Original Array = {1,0,2,1}

// encoded = {6,2,7,3}     first = 4
// Original Array = {4,2,0,7,4}

int main(){
    std::vector<TestHolder*> testSet = {
        new TestHolder(std::vector<int>{1,2,3}, 1),
        new TestHolder(std::vector<int>{6,2,7,3}, 4)
    };

    for(TestHolder* test : testSet){
        std::cout << "encoded = {";
        for(int i = 0; i < test->encoded.size(); i++){
            std::cout << test->encoded[i] << (i == (test->encoded.size() - 1)? "}":",");
        }
        std::cout << "\tfirst = "<< test->first << std::endl;

        std::vector<int> arr = decode(test->encoded, test->first);
        std::cout << "Original Array = {";
        for(int i = 0; i < arr.size(); i++){
            std::cout << arr[i] << (i == (arr.size() - 1)? "}":",");
        }
        std::cout << std::endl << std::endl;
    }

    return 0;
}