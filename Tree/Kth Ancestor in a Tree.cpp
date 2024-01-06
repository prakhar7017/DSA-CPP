Node* solve(Node *root, int &k, int &node){
    if(!root){
        return NULL;
    }
    
    if(root->data==node){
        return root;
    }
    
    Node* leftAns=solve(root->left,k,node);
    Node* rightAns=solve(root->right,k,node);
    
    if(leftAns && !rightAns){
        k--;
        if(k<=0){
            //answer lock
            k=INT_MAX;
            return root;
        }
        
        return leftAns;
    }
    if(!leftAns && rightAns){
        k--;
        if(k<=0){
            //answer lock
            k=INT_MAX;
            return root;
        }
        
        return rightAns;
    }
}
int kthAncestor(Node *root, int k, int node)
{
    if(!root){
        return -1;
    }
    
    Node* ans=solve(root,k,node);
    
    if(!ans || ans->data==node){
        return -1;
    }else{
        return ans->data;
    }
}

// time complexity: O(n)