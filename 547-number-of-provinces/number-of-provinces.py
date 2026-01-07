class Solution:
    def findParent(self,x):
        if(self.parent[x]==x):
            return x
        self.parent[x]=self.findParent(self.parent[x])
        return self.parent[x]

    def Union(self,x,y):
        x = self.findParent(x)
        y = self.findParent(y)

        if x == y: 
            return

        if(self.rank[x]<self.rank[y]):
            self.parent[x]=y
        elif (self.rank[x]>self.rank[y]):
            self.parent[y]=x
        else:
            self.parent[y]=x
            self.rank[x]+=1

        self.components-=1       

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        self.components = n
        self.parent=[i for i in range(n)]
        self.rank = [0]*n

        for i in range(n):
            for j in range(n):
                if isConnected[i][j]==1:
                    self.Union(i,j)

        return self.components



        