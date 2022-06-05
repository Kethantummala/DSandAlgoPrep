from SLL import SinglyLinkedList

class HashTable:

    def __init__(self,c=10,lf=0.7):
        self.capacity=c
        self.loadFactor=lf
        self.size=0
        self.container=[]
        for i in range(self.capacity):
            self.container.append(SinglyLinkedList())
    
    def getHash(self,val):
        return val

    def resize(self):
        self.capacity*=2
        ncontainer=[]
        for i in range(self.capacity):
            ncontainer.append(SinglyLinkedList())
        for i in range(len(self.container)):
            temp=self.container[i].head
            while temp:
                ncontainer[temp.data%self.capacity].append(temp.data)
                temp=temp.next
        self.container=ncontainer
    
    def insert(self,val):
        if (self.size/self.capacity)==self.loadFactor:
            self.resize()
        h=self.getHash(val)%(self.capacity)
        self.container[h].append(val)
    
    def isPresent(self,val):
        h=self.getHash(val)%(self.capacity)
        temp=self.container[h].head
        while temp:
            if temp.data==val:
                return True
            temp=temp.next
        return False
    
    def printHashTable(self):
        for i in range(len(self.container)):
            print("Key:",i,end=" : ")
            self.container[i].printList()

h=HashTable()
h.insert(2)
h.insert(5)
h.insert(7)
h.insert(15)
h.insert(23)
h.printHashTable()
print(h.isPresent(5))
print(h.isPresent(25))