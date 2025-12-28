import collections
class Solution:
    def bfs(self,start_node,adj):
        queue = collections.deque([start_node])
        visited = {start_node}
        while queue:
            curr = queue.popleft()
            for neighbour in adj[curr]:
                if neighbour not in visited:
                    visited.add(neighbour)
                    queue.append(neighbour)
        return len(visited)            
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        n = len(bombs)
        adj = collections.defaultdict(list)

        for i in range(n):
            for j in range(n):
                if i == j :
                    continue
                xi , yi , ri = bombs[i]
                xj , yj , rj = bombs[j]

                if (xi-xj)**2 + (yi-yj)**2 <= ri**2:
                    adj[i].append(j)

        max_bombs = 0
        for i in range(n):
            max_bombs = max(max_bombs,self.bfs(i,adj))

        return max_bombs            
        