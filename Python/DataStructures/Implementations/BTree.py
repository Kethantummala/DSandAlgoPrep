from Stack import Stack
import sys

class TNode:

    def __init__(self,val):
        self.data=val
        self.left=None
        self.right=None

class BinaryTree:

    def __init__(self,val):
        self.root=TNode(val)
    
    def inOrder(self):
        if self.root.left:
            self.root.left.inOrder()
        print(self.root.data)
        if self.root.right:
            self.root.right.inOrder()
    
    def preOrder(self):
        print(self.root.data)
        if self.root.left:
            self.root.left.preOrder()
        if self.root.right:
            self.root.right.preOrder()
    
    def postOrder(self):
        if self.root.left:
            self.root.left.postOrder()
        if self.root.right:
            self.root.right.postOrder()
        print(self.root.data)
    
    def levelOrder(self):
        q=[]
        temp=self
        i=0
        count=0
        while temp:
            print(temp.root.data)
            if temp.root.left:
                q.append(temp.root.left)
                count+=1
            if temp.root.right:
                q.append(temp.root.right)
                count+=1
            if count!=0:
                temp=q[i]
                count-=1
                i+=1
            else:
                temp=None
    
    def getMax(self):
        a=0
        b=self.root.data
        c=0
        if self.root.left:
            a=self.root.left.getMax()
        if self.root.right:
            c=self.root.right.getMax()
        return max(a,b,c)
    
    def search(self,val):
        if self.root.data==val:
            return True
        ans=False
        if self.root.left:
            ans=ans or self.root.left.search(val)
        if self.root.right:
            ans=ans or self.root.right.search(val)
        return ans
    
    def reverseLevelOrder(self):
        q=[]
        s=[]
        temp=self
        i=0
        count=0
        while temp:
            s.append(temp.root.data)
            if temp.root.left:
                q.append(temp.root.left)
                count+=1
            if temp.root.right:
                q.append(temp.root.right)
                count+=1
            if count!=0:
                temp=q[i]
                count-=1
                i+=1
            else:
                temp=None
        while len(s)!=0:
            print(s.pop())
    
    def getHeight(self,h=1):
        h1=0
        h2=0
        if self.root.left:
            h1=self.root.left.getHeight(h+1)
        if self.root.right:
            h2=self.root.right.getHeight(h+1)
        return max(h,h1,h2)
    
    def getDeepest(self,d=0):
        d1=0
        d2=0
        v1=0
        v2=0
        ans=(d,self.root.data)
        if self.root.left:
            (d1,v1)=self.root.left.getDeepest(d+1)
            if d1>d:
                ans=(d1,v1)
        if self.root.right:
            (d2,v2)=self.root.right.getDeepest(d+1)
            if d2>d:
                ans=(d2,v2)
        return ans

bt=BinaryTree(2)
bt.root.left=BinaryTree(7)
bt.root.left.root.left=BinaryTree(2)
bt.root.left.root.right=BinaryTree(6)
bt.root.right=BinaryTree(5)
bt.root.right.root.right=BinaryTree(9)
print("Inorder:")
bt.inOrder()
print("preorder:")
bt.preOrder()
print("postorder:")
bt.postOrder()
print("levelorder:")
bt.levelOrder()
print("Max:")
print(bt.getMax())
print("Searching 9:")
print(bt.search(9))
print("Reverse levelorder:")
bt.reverseLevelOrder()
print("Height:")
print(bt.getHeight())
print("Deepest node value:")
print(bt.getDeepest())