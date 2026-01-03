class Solution:

    def findParent(self,x):
        if self.parentArr[x]==x:
            return x
        self.parentArr[x]=self.findParent(self.parentArr[x])
        return self.parentArr[x]

    def Union(self,parent,child):
        child_ka_parent = self.findParent(child)
        if child_ka_parent != child:
            return False
        parent_ka_parent = self.findParent(parent)
        if parent_ka_parent == child:
            return False
        self.parentArr[child]=parent
        self.components-=1
        return True            
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        self.components = n
        self.parentArr = [i for i in range(n)]

        for i in range(n):
            parent = i
            left_child = leftChild[i]
            right_child = rightChild[i]
            if left_child!=-1 and self.Union(parent,left_child)==False:
                return False

            if right_child != -1 and self.Union(parent,right_child)==False:
                return False
        
        return self.components == 1

        
        