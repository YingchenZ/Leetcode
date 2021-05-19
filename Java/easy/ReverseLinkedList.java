import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
 
class Solution {
    public static ListNode reverseList(ListNode head) {
        ListNode prev = null;
        
        while(head != null){
            ListNode post = head.next;
            head.next = prev;
            prev = head;
            head = post;
        }
        return prev;
    }

    // Original: 1 2 3 4 5
    // Reversed: 5 4 3 2 1

    public static void main(String[] args){
        ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, null)))));
        ListNode start = head;
        System.out.print("Original:");
        while(start != null){
            System.out.print(" " + start.val);
            start = start.next;
        }
        head = reverseList(head);
        System.out.print("\nReversed:");
        while(head != null){
            System.out.print(" " + head.val);
            head = head.next;
        }
    }
}