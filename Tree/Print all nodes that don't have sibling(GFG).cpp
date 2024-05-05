/*

    Print all nodes that don't have sibling
    Given a Binary Tree of n nodes, find all the nodes that don't have any siblings. You need to return a list of integers containing all the nodes that don't have a sibling in sorted order (Increasing).

    Two nodes are said to be siblings if they are present at the same level, and their parents are the same.

    Note: The root node can not have a sibling so it cannot be included in our answer.

*/

Node* findNotASibling(Node* root,vector<int>&ans){
    // base case
    if(root==nullptr) return nullptr;
    Node* leftAns=findNotASibling(root->left,ans);
    Node* rightAns=findNotASibling(root->right,ans);
    
    if(leftAns!=nullptr && rightAns==nullptr){
        ans.push_back(leftAns->data);
    }
    if(leftAns==nullptr && rightAns!=nullptr){
        ans.push_back(rightAns->data);
    }
    return root;
}
vector<int> noSibling(Node* node)
{
    vector<int>ans;
    Node* a=findNotASibling(node,ans);
    sort(begin(ans),end(ans));
    if(ans.size()==0){
        return {-1};
    }
    return ans;
}

// time complexity:O(n)
// space complexity:O(h)