#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

ListNode* reversed(ListNode* head){
    ListNode* prev = head;
    ListNode* headCopy = head;
    ListNode* post = head->next;
    head = head->next;
    while(head){
        post = head->next;
        head->next = prev;
        prev = head;
        head = post;
    }
    headCopy->next = nullptr;
    return prev;
}

ListNode* reverseList(ListNode* head) {
    if(!head or !head->next)
        return head;
    return reversed(head);
}


int main(){
    ListNode* one = new ListNode(1, nullptr);
    ListNode* two = new ListNode(2, nullptr);
    ListNode* three = new ListNode(3, nullptr);
    ListNode* four = new ListNode(4, nullptr);
    ListNode* five = new ListNode(5, nullptr);
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    ListNode* start = one;
    std::cout << "Original:";
    while(start){
        std::cout << " " << start->val;
        start = start->next;
    }
    std::cout << "\nReversed:";;
    ListNode* head = reverseList(one);
    while(head){
        std::cout << " " << head->val;
        head = head->next;
    }
    return 0;
}