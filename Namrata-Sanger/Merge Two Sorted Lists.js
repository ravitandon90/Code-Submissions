/*
Day 7
21. Merge Two Sorted Lists.js
https://leetcode.com/problems/merge-two-sorted-lists/
*/

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) {
    let s, p = list1, q=list2;
    let newHead;
    if( p == null) { return q };
    if( q == null) { return p };
    if(list1?.val <= list2?.val){
        s = list1;
        p = s.next;
        q = list2;
    }else{
        s = list2;
        p = list1;
        q = s.next;
    }
    newHead = s;
    while(p != null && q != null){
       if(p.val <= q.val){
           s.next = p;
           s = p;
           p = s.next;
       }else if(q.val < p.val){
           s.next = q;    
           s = q;
           q = s.next;
       }
    }
    if(p == null & q != null){
        s.next = q;
    }else if(q==null && p!=null){
        s.next = p;
    }
    return newHead;
};
