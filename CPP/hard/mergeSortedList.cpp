#include <queue>
#include <vector>
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    // ============================= Method I =============================
    if(lists.size() == 0) return nullptr;

    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap = {};
    for(int i = 0; i < lists.size(); i++){
        while(lists[i]){
            minHeap.push(lists[i]->val);
            lists[i] = lists[i]->next;
        }
    }

    if(minHeap.size() == 0) return nullptr;
    ListNode* head;
    ListNode* pointer = new ListNode(minHeap.top());
    head = pointer;
    minHeap.pop();
    while(minHeap.size() != 0){
        pointer->next = new ListNode(minHeap.top());
        minHeap.pop();
        pointer = pointer->next;
    }
    

    return head;

    // ============================= Method II =============================
    // if(lists.size() == 0) return nullptr;
    // int zeroCount = 0;
    // for(int i = 0; i < lists.size(); i++){
    //     zeroCount += (!lists[i]);
    // }
    // if(zeroCount == lists.size()) return nullptr;

    // int length = lists.size();

    // ListNode* result = nullptr;
    // ListNode* copyHead = new ListNode();
    // result = copyHead;
    // ListNode* tail =nullptr;
    // int emptyCount = 0;
    // while(emptyCount < length){
    //     int minIndex = -1;
    //     emptyCount = 0;
    //     for(int i = 0; i < lists.size(); i++){
    //         if(!lists[i]){
    //             emptyCount++;
    //             continue;
    //         }
    //         if(minIndex == -1){
    //             minIndex = i;
    //         }
    //         if(lists[minIndex]->val > lists[i]->val){
    //             minIndex = i;
    //         }
    //     }
    //     if(emptyCount == length) break;
    //     copyHead->val = lists[minIndex]->val;
    //     lists[minIndex] = lists[minIndex]->next;

    //     copyHead->next = new ListNode();
    //     tail = copyHead;
        
    
        
    //     // std::cout << copyHead->val << " ";
        
    //     copyHead = copyHead->next;
        
    // }

    // // while(result){
    // //     std::cout << result->val;
    // //     result = result->next;
    // // }
    // tail->next = nullptr;
    // // std::cout << tail->val << " ";
    // return result;
}


// Test set
//  1 4 5
//  1 3 4
//  2 6
// After Sorting: 1 1 2 3 4 4 5 6

int main(){
    std::vector<std::vector<int>> test = {
        {1, 4, 5}, 
        {1, 3, 4}, 
        {2, 6}
    };

    std::vector<ListNode*> testSet(test.size(), new ListNode());
    for(int i = 0; i < test.size(); i++){
        ListNode* current = new ListNode();
        ListNode* head = current;
        for(int j = 0; j < test[i].size(); j++){
           current->val = test[i][j];
            if(j != test[i].size() - 1){
                current->next = new ListNode();
                current = current->next;
            }
        }
        testSet[i] = head;
    }

    std::cout << "Test set"<< std::endl;
    for(std::vector<int> vec : test){
        for(int num : vec){
            std::cout << " " << num ;
        }
        std::cout << std::endl;
    }

    ListNode* answer = mergeKLists(testSet);
    std::cout << "After Sorting:";
    while(answer){
        std::cout << " " << answer->val;
        answer = answer->next;
    }
    return 0;
}