class Solution {
    private:
    void printLeftBoundary(Node* root,vector<int>&leftAns){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            return;
        }
        
        leftAns.push_back(root->data);
        
        if(root->left!=NULL){
            printLeftBoundary(root->left,leftAns);
        }else{
            printLeftBoundary(root->right,leftAns);
        }
    }
    void printLeafNode(Node* root,vector<int>&leafAns){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            leafAns.push_back(root->data);
        }
        printLeafNode(root->left,leafAns);
        printLeafNode(root->right,leafAns);
    }
    void printRightNode(Node* root,vector<int>&rightAns){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            return;
        }
        if(root->right!=NULL){
            printRightNode(root->right,rightAns);
        }else{
            printRightNode(root->left,rightAns);
        }
        rightAns.push_back(root->data);
    }
    void solve(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->data);
        printLeftBoundary(root->left,ans);
        printLeafNode(root->left,ans);
        printLeafNode(root->right,ans);
        printRightNode(root->right,ans);
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};