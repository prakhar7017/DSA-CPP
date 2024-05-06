/*
    Reverse Level Order Traversal

    Given a binary tree of size n, find its reverse level order traversal. ie- the traversal must begin from the last level.

*/

vector<int> reverseLevelOrder(Node *root)
{
    vector<int>ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* frontNode=q.front();
        q.pop();
        ans.push_back(frontNode->data);
        if(frontNode->right){ // key note is to push right node first and then left node
            q.push(frontNode->right);
        }
        if(frontNode->left){
            q.push(frontNode->left);
        }
    }
    reverse(begin(ans),end(ans));
    return ans;
}

// time complexity o(n);
// space complexity o(n);