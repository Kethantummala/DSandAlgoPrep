def bft(graph,start):
    q=[start]
    while q!=[]:
        n=q[0]
        print(n)
        q=q[1:]
        for i in graph[n]:
            q.append(i)

graph={
    'a':['c','b'],
    'b':['d'],
    'c': ['e'],
    'd': ['f'],
    'e': [],
    'f': []
}

bft(graph,'a')