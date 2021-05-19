#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;

    while(head){
        ListNode* post = head->next;
        head->next = prev;
        prev = head;
        head = post;
    }
    return prev;
}

// Original: 1 2 3 4 5
// Reversed: 5 4 3 2 1

int main(){
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
    ListNode* start = head;
    std::cout << "Original:";
    while(start){
        std::cout << " " << start->val;
        start = start->next;
    }
    std::cout << "\nReversed:";;
    head = reverseList(head);
    while(head){
        std::cout << " " << head->val;
        head = head->next;
    }
    return 0;
}