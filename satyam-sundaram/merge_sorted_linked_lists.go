/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
    if list1 == nil {
        return list2
    }
    if list2 == nil {
        return list1
    }
    // Consider the below invariants -
    // 1. p1 - points to smaller node
    // 2. p2 - points to larger node
	// 3. p1 and p2 can be equal
    p1, p2 := list1, list2
    // Fix invariant violation
    if p1.Val > p2.Val {
        p1, p2 = p2, p1
    }
    head := p1
    last := p1
    for p1 != nil {
        // Fix invariant violation
        if p1.Val > p2.Val {
            p1, p2 = p2, p1
        }
        // Traverse till the last node which is smaller than p2.
        for p1 != nil && p1.Val <= p2.Val {
            last = p1
            p1 = p1.Next
        }
        // connect to the larger node p2
        last.Next = p2
    }
    return head
}