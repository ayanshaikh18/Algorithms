from random import randint

class Graph:
    def __init__(self, nodes):
        self.nodes = nodes
        self.edges=[]
        self.adj_list={}
        for i in range(nodes):
            self.adj_list[i]=[]
        
    def addEdge(self, src, dest):
        self.edges.append([src,dest])
        self.adj_list[src].append(dest)
        self.adj_list[dest].append(src)
        
    def findVertexCoverAproximation(self):
        cover = set()
        edges = self.edges
        while len(edges) != 0 :
            index=randint(0,len(edges)-1)
            u=edges[index][0]
            v=edges[index][1]
            cover.add(u + 1)
            cover.add(v + 1)
            edges = [edge for edge in edges if u not in edge and v not in edge]
        return cover
    
    def findVertexCoverAproximationGreedy(self):
        cover = set()
        edges = self.edges
        adj_list = self.adj_list
       
        while len(edges) != 0:
            max_degree = 0
            for v in adj_list:
                if len(adj_list[v]) > max_degree:
                    max_degree = len(adj_list[v])
                    index = v
        
            cover.add(index + 1)
            e1 = []
            for edge in edges:
                if edge[0] == index or edge[1] == index:
                    continue
                e1.append(edge)
            edges=e1
            del adj_list[index]
        return cover
        
n = int(input("Enter No. of Vertices : "))
g = Graph(n)
e = int(input("Enter No. of Edges : "))
print("Enter edges (Source, Destination)")
for _ in range (e):
    src, dest = map (int, input().split())
    g.addEdge(src-1,dest-1)

print("Vertex Cover using aproximation : ",g.findVertexCoverAproximation())
print("Vertex Cover using greedy aproximation : ",g.findVertexCoverAproximationGreedy())