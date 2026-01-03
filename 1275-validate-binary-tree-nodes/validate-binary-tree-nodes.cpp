class Solution {
public:
    vector<int>parentArr;
    int components;
    int findParent(int x) {
        if (parentArr[x]==x) return x;
        return parentArr[x]=findParent(parentArr[x]);
    }
    bool Union(int parent,int child){
        int child_ka_parent = findParent(child);
        if(child_ka_parent != child) return false;
        int parent_ka_parent = findParent(parent);
        if (parent_ka_parent == child) return false;

        parentArr[child]=parent;
        components--;
        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        components = n;
        parentArr.resize(n);
        iota(begin(parentArr),end(parentArr),0);

        for(int i=0;i<n;i++){
            int parent = i;
            int left_child = leftChild[i];
            int right_child = rightChild[i];
            if(left_child!=-1 && !Union(parent,left_child)) return false;
            if (right_child!=-1 && !Union(parent,right_child)) return false;
        }

        return components == 1;

    }
};