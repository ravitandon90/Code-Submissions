class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        
        ListNode dummy = new ListNode(-1);
        ListNode itr = dummy;
        
        ListNode up = list1;
        ListNode down = list2;
        
        while(up != null && down != null)
        {
            if(up.val >= down.val)
            {
                itr.next = down;
                down = down.next;
            }
            else
            {
                itr.next = up;
                up = up.next;
            }
            
            itr = itr.next;
        }
        
        while(up != null)
        {
            itr.next = up;
            up = up.next;
            itr = itr.next;
            
        }
        
        while(down != null)
        {
            itr.next = down;
            down = down.next;
            itr = itr.next;
        }
        
        return dummy.next;
    }
}
