/*
    Construct Binary Tree from Inorder and Postorder

    Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays in[] and post[] respectively. The task is to construct a binary tree from these traversals.

    Driver code will print the preorder traversal of the constructed tree.

*/

class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    // IMP pass the postOrderIdx by reference so that it can be updated in the recursive calls
    Node* buildBinaryTree(unordered_map<int,int>&mp,int in[], int post[],int &postIndex,int s,int e,int &n){
        // base case
        if(postIndex<0 || s>e){
            return nullptr;
        }
        int element=post[postIndex];
        Node* root= new Node(element);
        --pI;
        int position=mp[element];
        root->right=buildBinaryTree(mp,in,post,postIndex,position+1,e,n); // IMPORTANT: first right then left
        root->left=buildBinaryTree(mp,in,post,postIndex,s,position-1,n);
        return root;
    }
    Node *buildTree(int in[], int post[], int n) {
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[in[i]]=i;
        }
        int postOrderIdx=n-1;
        int inOrderStart=0;
        int inOrderEnd=n-1;
        return buildBinaryTree(mp,in,post,postOrderIdx,inOrderStart,inOrderEnd,n);
    }
};

// time complecity: O(n)
// space complecity: O(n)