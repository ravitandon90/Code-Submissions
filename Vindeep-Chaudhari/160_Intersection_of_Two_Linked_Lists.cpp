/**
 * Problem Link - https://leetcode.com/problems/intersection-of-two-linked-lists/
 */

// First 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *current1 = headA;
		ListNode *current2 = headB;
		while(current1 != current2){
            current1 = current1 -> next;
            current2 = current2 -> next;
            
            if(current1 == current2) return current1;
            
			if(current1 == NULL){
				current1 = headB;
			}
			
			if(current2 == NULL){
				current2 = headA;
			}
            
		}
		return current1;
        
    }
};

// Second

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_map <ListNode*, bool> mp;
        
        ListNode* curr = headA;
        while (curr != NULL) {
            mp[curr] = true;
            curr = curr->next;
        }
        
        curr = headB;
        while(curr != NULL) {
            if(mp.find(curr) != mp.end()) {
                return curr;
            }
            
            curr = curr->next;
        }
        
        return NULL;
        
    }
};