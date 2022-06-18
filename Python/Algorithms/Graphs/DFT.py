def dft(graph,start):
    print(start)
    for i in graph[start]:
        dft(graph,i)

graph={
    'a':['c','b'],
    'b':['d'],
    'c': ['e'],
    'd': ['f'],
    'e': [],
    'f': []
}

dft(graph,'a')