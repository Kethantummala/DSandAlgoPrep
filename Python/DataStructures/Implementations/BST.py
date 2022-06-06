class TNode:

    def __init__(self,val):
        self.data=val
        self.left=None
        self.right=None

class BinarySearchTree:

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
    
    def insert(self,val):
        if self.root.data<val:
            if self.root.right:
                self.root.right.insert(val)
            else:
                self.root.right=BinarySearchTree(val)
        else:
            if self.root.left:
                self.root.left.insert(val)
            else:
                self.root.left=BinarySearchTree(val)

    def getMin(self):
        if self.root.left:
            return self.root.left.getMin()
        return self.root.data

    def delete(self,val):
        if self.root.data==val:
            if self.root.left and self.root.right:
                self.root.data=self.root.left.getMin()
                self.root.left=self.root.left.delete(self.root.data)
                return self
            elif self.root.left:
                return self.root.left
            elif self.root.right:
                return self.root.right
            else:
                return None
        elif self.root.data<val:
            if self.root.right:
                self.root.right=self.root.right.delete(val)
        else:
            if self.root.left:
                self.root.left=self.root.left.delete(val)
        return self

bst=BinarySearchTree(5)
bst.insert(7)
bst.insert(3)
bst.insert(4)
bst.insert(23)
bst.insert(15)
bst.insert(10)
bst.insert(17)
bst.insert(25)
bst.levelOrder()
print("Sorted Data:")
bst.inOrder()#Gets sorted data
print("Deleting 3:")
bst.delete(3)
bst.levelOrder()
print("Deleting 4:")
bst.delete(4)
bst.levelOrder()
print("Deleting 23:")
bst.delete(23)
bst.levelOrder()