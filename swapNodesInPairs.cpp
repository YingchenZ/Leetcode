#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if(!head) return head;
    if(!head->next) return head;

    ListNode* newHead = head->next;

    ListNode* prev = head;
    
    while(head){
        head = head->next; //2
        ListNode* afterHead = head?head->next:nullptr;//3
        if(head)
            head->next = prev;
        prev->next = afterHead?afterHead->next:nullptr;
        if(afterHead && !afterHead->next){
            prev->next = afterHead;
            break;
        }
        head = afterHead;
        prev = head;
    }

    return newHead;
}

// Before Swapping: 0->1->2->3->4->5->6->7->8->9->10->11->12->13->14->15->16->17->18->19
// After Swapping:  1->0->3->2->5->4->7->6->9->8->11->10->13->12->15->14->17->16->19->18

int main(){
    ListNode* head = new ListNode(0, nullptr);
    std::cout << "Before Swapping: "<< head->val;
    ListNode* headCopy = head;
    for(int i = 1; i < 20; i++){
        ListNode *newElement = new ListNode(i,nullptr);
        std::cout << "->"<<i;
        // std::cout << head->val << (i + 1== 20? "\n":"->");
        head->next = newElement;
        head = head->next;
    }
    std::cout << "\nAfter Swapping:  ";
    ListNode* result = swapPairs(headCopy);
    for(ListNode* i = result; i; i = i->next){
        std::cout << i->val << (i->next?"->":"");
    }
    return 0;
}