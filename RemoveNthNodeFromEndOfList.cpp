/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int& n) {
        if(head == nullptr){
            n--;
            return head;
        }
        head->next = removeNthFromEnd(head->next, n);
        if(n == 0){
            n--;
            return head->next;
        }
        else{
            n--;
            return head;
        }
    }
};