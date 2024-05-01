/*

    Serialize and deserialize a binary tree
    Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

    serialize() : stores the tree into an array a and returns the array.
    deSerialize() : deserializes the array to the tree and returns the root of the tree.
    Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).

*/

class Solution
{
    public:
    void inOrder(Node* root,vector<int>&ans){
        if(!root) return ;
        inOrder(root->left,ans);
        ans.push_back(root->data);
        inOrder(root->right,ans);
    }
    Node* buildTree(vector<int>&a,int s,int e){
        if(s>e) return nullptr;
        
        int mid=s+(e-s)/2;
        int element=a[mid];
        
        Node* root=new Node(element);
        
        root->left=buildTree(a,s,mid-1);
        root->right=buildTree(a,mid+1,e);
        
        return root;
    }
    vector<int> serialize(Node *root) 
    {
        vector<int>ans;
        inOrder(root,ans);
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
        int s=0;
        int e=A.size()-1;
        return buildTree(A,s,e);
    }

};

// time complexity of serialize: O(n)
// space complexity of serialize: O(n)
// time complexity of deSerialize: O(n)
// space complexity of deSerialize: O(n)