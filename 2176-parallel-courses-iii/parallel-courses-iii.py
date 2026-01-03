from collections import deque, defaultdict
class Solution(object):
    def toposort(self,n,max_time,indegree,time,adj):
        que = deque()
        for i in range(1,n+1):
            if indegree[i]==0:
                que.append(i)
                max_time[i] = time[i-1]

        while que:
            curr_course = que.popleft()
            for next_course in adj[curr_course]:
                max_time[next_course] = max(max_time[next_course],max_time[curr_course]+time[next_course-1])
                indegree[next_course]-=1
                if indegree[next_course]==0:
                    que.append(next_course)         
    def minimumTime(self, n, relations, time):
        adj = defaultdict(list)
        indegree = [0]*(n+1)

        for prev_course,next_course in relations:
            adj[prev_course].append(next_course)
            indegree[next_course]+=1

        maxTime = [0]*(n+1)
        self.toposort(n,maxTime,indegree,time,adj)
        return max(maxTime)
        