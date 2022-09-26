class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        output = ListNode(val = 0)
        p = output
        c = 0
        while l1 != None or l2 != None or c != 0:
            v1 = l1.val if l1 != None else 0
            v2 = l2.val if l2 != None else 0
            
            s = c + v1 + v2
            
            p.next = ListNode(s % 10)
            p = p.next
            
            c = int(s / 10)
            
            l1 = l1.next if l1 != None else None
            l2 = l2.next if l2 != None else None
        
        return output.next
