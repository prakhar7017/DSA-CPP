class Solution{
public:
    bool levelorderTraversal(Node* root){
        queue<Node*>q;
        q.push(root);
        bool nullFound=false;
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            if(front==NULL){
                nullFound=true;
            }else{
                if(nullFound) return false;
                
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
    bool isCompleteBT(Node* root){
        return levelorderTraversal(root);
    }
};

// time complexity: O(n)
// space complexity: O(n)

// level order traverse karte hue if ek baar null milgya toh baad me koi node nhi aana chahiye
//agar arhi hh toh  iska mtlb tree complete nhi hh 

                10
            /       \
          20        30
        /   \      /   \        
        X   50    60   70

// null ke baad node hh toh tree complete nhi hh

                10
            /       \
          20        30
        /   \      /   \        
       40   50    60   70