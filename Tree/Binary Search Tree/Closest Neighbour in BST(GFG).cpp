// Problem : Closest Neighbour in BST
// Description : Given the root of a binary search tree and a number n, find the greatest number in the binary search tree that is less than or equal to n. 

class Solution {
  public:
    int findMaxForN(Node* root, int n) {
        Node* temp=root;
        int ans=INT_MIN;
        while(temp!=NULL){
            if(temp->key==n){
                ans=max(ans,temp->key);
                break;
            }else if(temp->key>n){
                temp=temp->left;
            }else if(temp->key<n){
                ans=max(ans,temp->key);
                temp=temp->right;
            }
        }
        return ans==INT_MIN ? -1 : ans;
    }
};

// time complexity:O(h)
// space complexity:O(1)

//link : https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1 