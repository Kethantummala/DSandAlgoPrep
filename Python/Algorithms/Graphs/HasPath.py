def hasPath(graph,source,destination):
    #Breadth first implementation
    q=[source]
    while q!=[]:
        n=q[0]
        if n==destination:
            return True
        q=q[1:]
        for i in graph[n]:
            q.append(i)
    return False

graph={
    'f':['g','i'],
    'g':['h'],
    'h': [],
    'i': ['g','k'],
    'j': ['i'],
    'k': []
}

print(hasPath(graph,'f','j'))