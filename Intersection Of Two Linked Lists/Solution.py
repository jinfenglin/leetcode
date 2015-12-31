# Definition for singly-linked list.
class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        Acount=0
        Bcount=0
        pa=headA
        pb=headB
        while pa!=None:
            pa=pa.next
            Acount+=1
        while pb!=None:
            pb=pb.next
            Bcount+=1
        dif=Acount-Bcount
        while dif>0:
            headA=headA.next
            dif-=1
        while dif<0:
            headB=headB.next
            dif+=1
        while headA!=headB:
            headA=headA.next
            headB=headB.next
        return headA
