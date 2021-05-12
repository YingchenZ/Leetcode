#include <vector>
#include <iostream>

std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
    std::vector<int> xorArr(arr.size() + 1, 0);
    std::vector<int> ans(queries.size(),0);
    for(int i = 1; i <= arr.size(); i++){
        xorArr[i] = xorArr[i - 1] ^ arr[i - 1];
    }

    for(int i = 0; i < queries.size(); i++){
        ans[i] = xorArr[queries[i][1] + 1] ^ xorArr[queries[i][0]];
    }

    return ans;
}

struct TestHolder{
    std::vector<int> arr;
    std::vector<std::vector<int>> queries;
    TestHolder(std::vector<int> a, std::vector<std::vector<int>> b) : arr(a), queries(b){}
};

// arr = {1,3,4,8}
// queries = {{0,1},{1,2},{0,3},{3,3}}
// XOR Array = {2,7,14,8}

// arr = {4,8,2,10}
// queries = {{2,3},{1,3},{0,0},{0,3}}
// XOR Array = {8,0,4,4}

int main(){
    std::vector<TestHolder*> testSet = {
        new TestHolder({1,3,4,8}, {{0,1},{1,2},{0,3},{3,3}}),
        new TestHolder({4,8,2,10}, {{2,3},{1,3},{0,0},{0,3}})
    };

    for(TestHolder* test : testSet){
        std::vector<int> arr = test->arr;
        std::vector<std::vector<int>> queries = test->queries;
        std::cout << "arr = {";
        for(int i = 0; i < arr.size(); i++){
            std::cout << arr[i] << (i == (arr.size() - 1)? "}\n":",");
        }
        std::cout << "queries = {";
        for(int i = 0; i < queries.size(); i++){
            std::cout << "{" << queries[i][0] << "," << queries[i][1] << "}" << (i == (queries.size() - 1)? "}\n":",");
        }
        std::cout << "XOR Array = {";
        std::vector<int> ans = xorQueries(arr, queries);
        for(int i = 0; i < ans.size(); i++){
            std::cout << ans[i] << (i == (ans.size() - 1)? "}\n\n":",");
        }
    }

    return 0;
}