import sys

class MaxHeap:

    def __init__(self,l=None) :
        if l:
            self.tree=l
            self.heapify2(0)
        else:
            self.tree=[]
    
    def insert(self,d):
        curIndex=len(self.tree)
        self.tree.append(d)
        parentIndex=(curIndex-1)//2
        while parentIndex>=0 and self.tree[curIndex]>self.tree[parentIndex]:
            temp=self.tree[curIndex]
            self.tree[curIndex]=self.tree[parentIndex]
            self.tree[parentIndex]=temp
            curIndex=parentIndex
            parentIndex=(curIndex-1)//2
    
    def getMax(self):
        ans=self.tree[0]
        self.tree[0]=self.tree.pop()
        self.heapify1(0)
    
    def heapify1(self,curIndex):
        lChildIndex=(curIndex*2)+1
        rChildIndex=(curIndex*2)+2
        n=len(self.tree)
        changingChildIndex=None
        if lChildIndex<n:
            if self.tree[lChildIndex]>self.tree[curIndex]:
                changingChildIndex=lChildIndex
        if rChildIndex<n:
            if self.tree[lChildIndex]>self.tree[curIndex]:
                if self.tree[rChildIndex]>self.tree[lChildIndex]:
                    changingChildIndex=rChildIndex

        if changingChildIndex!=None:
            temp=self.tree[curIndex]
            self.tree[curIndex]=self.tree[changingChildIndex]
            self.tree[changingChildIndex]=temp
            self.heapify1(changingChildIndex)
    
    def heapify2(self,curIndex):
        lChildIndex=(curIndex*2)+1
        rChildIndex=(curIndex*2)+2
        n=len(self.tree)
        changingChildIndex=None
        if lChildIndex<n:
            self.heapify2(lChildIndex)
            if self.tree[lChildIndex]>self.tree[curIndex]:
                changingChildIndex=lChildIndex
        if rChildIndex<n:
            self.heapify2(rChildIndex)
            if self.tree[lChildIndex]>self.tree[curIndex]:
                if self.tree[rChildIndex]>self.tree[lChildIndex]:
                    changingChildIndex=rChildIndex

        if changingChildIndex!=None:
            temp=self.tree[curIndex]
            self.tree[curIndex]=self.tree[changingChildIndex]
            self.tree[changingChildIndex]=temp
            self.heapify2(changingChildIndex)

    def display(self):
        print(self.tree)

mh=MaxHeap()
mh.insert(14)
mh.insert(12)
mh.display()
mh.insert(11)
mh.insert(9)
mh.insert(8)
mh.display()
mh.getMax()
mh.display()
mh2=MaxHeap([8,9,11,12,14])
mh2.display()