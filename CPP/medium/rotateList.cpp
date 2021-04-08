#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* rotateRight(ListNode* head, int k) {
    if(k == 0 || !head)
        return head;
    ListNode* front = head;
    ListNode* headCopy = head;

    int length = 1;
    while(headCopy->next){
        headCopy = headCopy->next;
        length++;
    }

    int newTailIndex = length - k % length;
    if(newTailIndex == length) return head;

    while(newTailIndex > 1){
        head = head->next;
        newTailIndex--;
    }

    ListNode* newHead = head->next;
    headCopy->next = front;
    head->next =nullptr;
    return newHead;
}

// [1,2,3] k = 2000000000 Result = 2 3 1

int main(){
    ListNode* head = new ListNode(1, nullptr);
    ListNode* middle = new ListNode(2, nullptr);
    ListNode* tail = new ListNode(3, nullptr);
    head->next = middle;
    middle->next = tail;

    ListNode* result = rotateRight(head, 2000000000);
    std::cout << "[1,2,3] k = 2000000000 Result =";
    for(; result; result = result->next){
        std::cout << " " << result->val;
    }
    std::cout << std::endl;
    return 0;
}