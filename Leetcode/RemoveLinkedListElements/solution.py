class Solution(object):
    def removeElements(self, head, val):
        Dummynode = ListNode(-1)
        Dummynode.next = head
        cur = Dummynode
        while cur != None and cur.next != None:
            if cur.next.val == val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        
        return Dummynode.next
