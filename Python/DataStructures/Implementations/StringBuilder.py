class StringBuilder:

    def __init__(self):
        self.container=[]
    
    def toString(self):
        return ''.join(map(str,self.container))
    
    def append(self,s):
        self.container.append(s)

sb=StringBuilder()
sb.append("abc")
sb.append("dca")
print(sb.toString())
sb.append("bdb")
print(sb.toString())