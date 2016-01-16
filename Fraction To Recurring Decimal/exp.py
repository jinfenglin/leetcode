class Node:
    def __init__(self,val):
        self.val=val
        self.next=None


head=Node(0)
tmp=Node(1)
print head.next
head.next= tmp
print head.next
print tmp
