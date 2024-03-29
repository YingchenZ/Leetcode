#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



//  1-> 2<-3<-4 5->6
//  pre     = L4
//  post    = L5
//  head    = L5
//  firstReversed = L1
//  reverseStart = 5
//  reversedNode = 3


ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(m - n == 0){
        return head;
    }
    ListNode* headCopy = head;
    int reverseStart = 1, reversedNode = 0;
    ListNode* firstReversed = nullptr, *pre = nullptr, *post = nullptr;
    // find the tail;
    while(head && (reversedNode <= n - m)){
        // if we found the start of the reversed list
        if(reverseStart == m){
            pre = head;
            head = head->next;
            pre->next = nullptr;
            reverseStart++;
            reversedNode++;
            continue;
        }
        if (reverseStart < m){
            firstReversed = head;
            reverseStart++;
            head = head->next;
            continue;
        }
        if(reverseStart >= m){
            // increment reversed node by 1
            reversedNode++;
        }

        // if the current node is the second node of the reversed list
        if(reversedNode >= 2){
            post = head->next;
            head->next = pre;
            pre = head;
            head = post;
        }
        else{
            head = head->next;
        }
        reverseStart++;
    }

    // start with head and 
    if(!firstReversed){
        // end at tail
        if(!head){
            ListNode* result = pre;
            headCopy->next = nullptr;
            return pre;
        }
        else{
            headCopy->next = post;
            return pre;
        }
        
    }
    // start after head and end at tail
    if(firstReversed and !head){
        if(firstReversed->next){
            firstReversed->next->next = nullptr;
        }
        firstReversed->next = pre;
        return headCopy;
    }


    firstReversed->next->next = post;
    firstReversed->next = pre;

    return headCopy;
}


// Original: 1 2 3 4 5
// Reversed: 1 4 3 2 5

int main(){
    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(4);
    ListNode* five = new ListNode(5);
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
    ListNode* head = reverseBetween(one, 2, 4);
    while(head){
        std::cout << " " << head->val;
        head = head->next;
    }
    return 0;
}
// [1,2,3,4,5]  m = 2   n = 4   =>  [1,4,3,2,5]
// [1,2,3,4,5]  m = 3   n = 4   =>  [1,2,4,3,5]
// [5]          m = 1   n = 1   =>  [5]
// [5,5,5,5,5]  m = 1   n = 5   =>  [5,4,3,2,1]
// [3,5]        m = 1   n = 2   =>  [5,3]
// [1,2,3]      m = 1   n = 2   =>  [2,1,3]
// [1,2,3]      m = 2   n = 3   =>  [1,3,2]