/**
 * Problem Link - https://leetcode.com/problems/merge-k-sorted-lists/
 */

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
    ListNode* mergeTwoLists(ListNode* node1, ListNode* node2) {
        if(node1 == NULL) return node2;
        if(node2 == NULL) return node1;
        
        ListNode* sorted = NULL;
        if(node1->val <= node2->val) {
            sorted = node1;
            sorted->next = mergeTwoLists(node1->next, node2);
        } else {
            sorted = node2;
            sorted->next = mergeTwoLists(node1, node2->next);
        }
        
        return sorted;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }

        return lists[0];
    }
};