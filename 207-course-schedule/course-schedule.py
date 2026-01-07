from collections import deque, defaultdict
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = defaultdict(list)
        indegree = [0]*numCourses
        
        for v,u in prerequisites:
            adj[u].append(v)
            indegree[v]+=1

        q = deque()

        for i in range(numCourses):
            if indegree[i]==0:
                q.append(i)

        ans = []        
        while q:
            curr_course = q.popleft()
            ans.append(curr_course)

            for next_course in adj[curr_course]:
                indegree[next_course]-=1
                if indegree[next_course] == 0:
                    q.append(next_course)

        return len(ans) == numCourses           


        