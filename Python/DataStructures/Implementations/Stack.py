class Stack:

    def __init__(self,c,l=None):
        if not l:
            self.capacity=c
            self.size=0
            self.container=[]
        elif(len(l)<=c):
            self.capacity=c
            self.size=c
            self.container=l
        else:
            raise Exception("Stack overflow")
    
    def push(self,val):
        if self.size==self.capacity:
            raise Exception("Stack overflow")
        else:
            self.container.append(val)
            self.size+=1
    
    def pop(self):
        if self.size==0:
            raise Exception("Stack underflow")
        else:
            self.size-=1
            return self.container.pop()
    
    def top(self):
        if self.size==0:
            print("Stack empty")
            return None
        else:
            return self.container[-1]
    
    def isEmpty(self):
        return self.size==0

s=Stack(5)
s.push(1)
print(s.top())
s.push(2)
s.push(3)
s.push(4)
print(s.top())
print(s.pop())
print(s.top())
print(s.isEmpty())
s.push(5)
s.push(6)
#s.push(7)
print(s.top())
print(s.pop())
print(s.pop())
print(s.pop())
print(s.pop())
print(s.pop())
#print(s.pop())
print(s.isEmpty())