/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    //21. Merge Two Sorted Lists https://leetcode.com/problems/merge-two-sorted-lists/
    //1. compare list head value and keep adding smaller values to the answer list.
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if(list1==null && list2==null){
            return null;
        }
        if(list1==null && list2!=null){
            return list2;
        }
        if(list2==null && list1!=null){
            return list1;
        }
        
        ListNode answer=null;
        if(list2.val>list1.val){
            answer=list1;
            list1=list1.next;
        }else{
           answer=list2;
            list2=list2.next;
        }
        ListNode temp= answer;
        while(list1!=null && list2!=null){
            if(list1.val<list2.val){
                temp.next=list1;
                list1=list1.next;
                
                
            }else{
                temp.next=list2;
                list2=list2.next;
            }
            temp=temp.next;
        }
        while(list1!=null){
               temp.next=list1;
                list1=list1.next;
            temp=temp.next;
            
        }
        while(list2!=null){
            temp.next=list2;
                list2=list2.next;
            temp=temp.next;
        }
        return answer;
    }
}
