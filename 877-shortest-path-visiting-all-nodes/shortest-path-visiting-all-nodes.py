from collections import deque
class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)
        if n<=1:
            return 0

        all_visited_state = (1<<n)-1 # pow(2,n)-1

        que = deque()
        vis = set()

        for i in range(n):
            mask_value = (1<<i)
            que.append((i,mask_value))
            vis.add((i,mask_value))

        result = 0    
        while que:
            size = len(que)
            result += 1
            for _ in range(size):
                curr_node, curr_mask = que.popleft()

                for neigh in graph[curr_node]:
                    next_mask = curr_mask | (1<<neigh)

                    if next_mask == all_visited_state:
                        return result

                    if (neigh, next_mask) not in vis:
                        vis.add((neigh,next_mask))
                        que.append((neigh,next_mask))     
        return -1           
        