import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    private static ListNode reverse(ListNode node){
        ListNode prev = null;

        while(node != null){
            ListNode post = node.next;
            node.next = prev;
            prev = node;
            node = post;
        }

        return prev;
    }

    private static ListNode findTailOfFirst(ListNode node){
        ListNode slow = node, fast = node;

        while(fast != null && fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    public static boolean isPalindrome(ListNode head) {
        ListNode firstHalfTail = findTailOfFirst(head);
        ListNode secondHead = reverse(firstHalfTail.next);
        
        while(head != null && secondHead != null){
            if(head.val != secondHead.val)  return false;
            head = head.next;
            secondHead = secondHead.next;
        }
        return true;
    }

    public static void printList(ListNode start){
        while(start != null){
            System.out.print(" " + start.val);
            start = start.next;
        }
    }

    // Head =  1 2 3 1 Not Palindromic    
    // Head =  1 2 2 1 Palindromic        
    // Head =  1 2 3 2 1       Palindromic

    public static void main(String[] args){
        ListNode test1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(1, null))));
        ListNode test2 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1, null))));
        ListNode test3 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(1, null)))));
        ListNode[] testSet = new ListNode[]{test1, test2, test3};

        for(ListNode test : testSet){
            System.out.print("Head = ");
            printList(test);
            System.out.println("\t" + (isPalindrome(test)?"":"Not ") + "Palindromic");
        }
    }
}