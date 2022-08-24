tion for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        ln = ListNode()
        root = ln
       
        if list1 is None:
            return list2
        elif list2 is None:
            return list1
       
        while list1 and list2:
            if list1.val < list2.val:
                ln.next = list1
                list1 = list1.next
                ln = ln.next
            elif list1.val > list2.val:
                ln.next = list2
                list2 = list2.next
                ln = ln.next
            else:
                ln.next = list1
                list1 = list1.next
                ln=ln.next
                ln.next=list2
                list2 = list2.next
                ln=ln.next
               
               
        while list1 is not None:
            ln.next=list1
            list1=list1.next
            ln=ln.next
           
        while list2 is not None:
            ln.next=list2
            list2=list2.next
            ln=ln.next
           
        return root.next
