import heapq
from collections import defaultdict
class Graph:

    def __init__(self, n: int, edges: List[List[int]]):
        self.N = n
        self.adj = defaultdict(list)
        for u,v,dist in edges:
            self.adj[u].append((v,dist))


    def addEdge(self, edge: List[int]) -> None:
        self.adj[edge[0]].append((edge[1],edge[2]))
        

    def shortestPath(self, node1: int, node2: int) -> int:
        result = [float('inf')]*self.N
        result[node1]=0 
        pq = [(0,node1)]
        while pq:
            curr_dist , curr_node = heapq.heappop(pq)

            if(curr_dist > result[curr_node]):
                continue

            for next_node , next_dist in self.adj[curr_node]:
                if(curr_dist+next_dist<result[next_node]):
                    result[next_node]=curr_dist+next_dist
                    heapq.heappush(pq,(result[next_node],next_node))

        return result[node2] if result[node2]!=float('inf') else -1            
        


# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)