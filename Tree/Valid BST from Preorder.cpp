void buildTree(vector<int>&A,int min,int max,int i){
    if(i>=A.size()){
        return;
    }
    if(A[i]>min && A[i]<max){
        int rootData=A[i++];
        buildTree(A,min,rootData,i);
        buildTree(A,rootData,max,i);
    }
}
int Solution::solve(vector<int>&A) {
    int i=0;
    int min=INT_MIN;
    int max=INT_MAX;
    buildTree(A,min,max,i);
    return i==A.size();
}

// time complexity:o(n)
// space complexity:o(n);

// we will create a a bst from preorder and if we are able to traverse whole array i.e i==A.size() then it is bst otherwise not.

// in invalid bsr we will not be able to traverse whole array 