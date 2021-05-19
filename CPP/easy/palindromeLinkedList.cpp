#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverse(ListNode* head){
    if(!head->next) return head;
    ListNode* prev = nullptr;
    ListNode* node = head;

    while(node){
        ListNode* post = node->next;
        node->next = prev;
        prev = node;
        node = post;
    }
    return prev;
}

ListNode* findFirstTail(ListNode* node){
    ListNode* slow = node;
    ListNode* fast = node;
    // fast pointer is always twice faster than the slow pointer
    // hence, this loop can find the half point of the list
    while(fast && fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

bool isPalindrome(ListNode* head) {
    ListNode* firstTail = findFirstTail(head);
    // firstTail's next will become the head of the second half
    ListNode* secondHead = reverse(firstTail->next? firstTail->next : firstTail);

    // no need to care if we checked the firstTail or not
    // if we have odd numbers of node   =>  firstTail is alone and it is palindromic
    // if we have even numbers of node  =>  firstTaill will be checked when head reached the end
    while(head && secondHead){
        if(head->val != secondHead->val)    return false;
        secondHead = secondHead->next;
        head = head->next;
    }
    
    return true;
}
void printList(ListNode* start){
    while(start){
        std::cout << " " << start->val;
        start = start->next;
    }
}

// Head = 1 2 3 1  Not Palindromic
// Head = 1 2 2 1  Palindromic
// Head = 1 2 3 2 1        Palindromic

int main(){
    ListNode* test1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(1, nullptr))));
    ListNode* test2 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1, nullptr))));
    ListNode* test3 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(1, nullptr)))));

    std::vector<ListNode*> testSet = {test1, test2, test3};
    for(ListNode* test : testSet){
        std::cout << "Head =";
        printList(test);
        std::cout << "\t" << (isPalindrome(test)? "":"Not ") << "Palindromic" << std::endl;
    }
    return 0;
}