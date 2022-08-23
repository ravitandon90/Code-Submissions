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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // when we reach the end of one list, we return the other
        if(l1 == nullptr) {
			return l2;
		}
		if(l2 == nullptr) {
			return l1;
		} 
		
        // when both the lists are having elements, we compare the head
        // return the one with the lesser number element
		if(l1 -> val <= l2 -> val) {
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		else {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
    }
};