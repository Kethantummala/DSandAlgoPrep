class Node:
    
    def __init__(self,val):
        self.data=val
        self.next=None
    
class SinglyLinkedList:

    def __init__(self):
        self.head=None

    def printList(self):
        temp=self.head
        print("Traversing Linked list:",end=" ")
        while temp!=None:
            print(temp.data,"->",end=" ")
            temp=temp.next
        print("None")
    
    def push(self,val):
        nnode=Node(val)
        temp=self.head
        self.head=nnode
        self.head.next=temp
    
    def insertAfter(self,onode,val):
        nnode=Node(val)
        if not onode:
            print("Given node must be in LinkedList/Not null")
            return
        nnode.next=onode.next
        onode.next=nnode
    
    def append(self,val):
        nnode=Node(val)
        if not self.head:
            self.head=nnode
        else:
            temp=self.head
            while temp.next:
                temp=temp.next
            temp.next=nnode
    
    def deleteNode(self,val):
        if not self.head:
            print("Given value not in the linked list.")
            return
        else:
            temp=self.head
            if(temp.data==val):
                self.head=temp.next
                print("Node with first occurence of given value is deleted.")
                return
            while temp.next:
                if temp.next.data==val:
                    temp2=temp.next.next
                    temp.next.next=None
                    temp.next=temp2
                    print("Node with first occurence of given value is deleted.")
                    return
                temp=temp.next
            print("Given value not in the linked list.")
            return

ll1=SinglyLinkedList()
ll1.head=Node(1)
ll1.head.next=Node(2)
ll1.head.next.next=Node(3)

ll1.printList()
ll1.push(4)
ll1.printList()
ll1.insertAfter(ll1.head.next,5)
ll1.printList()
ll1.append(6)
ll1.printList()
ll1.deleteNode(6)
ll1.printList()