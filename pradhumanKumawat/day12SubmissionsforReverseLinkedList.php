<?php

//Questions : Day 12 submissions for Reverse Linked List.

/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {

    /**
     * @param ListNode $head
     * @return ListNode
     */
    function reverseList($head) {
        return $this->newReverseList($head, null);
    }

    function newReverseList($head, $newHead){
        if($head ==null) return $newHead;
        $next =$head->next;
        $head->next = $newHead;
        return $this->newReverseList($next, $head);
    }
}