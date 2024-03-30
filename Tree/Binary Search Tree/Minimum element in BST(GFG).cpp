
// Problem Statement: Minimum element in BST
// Description : Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BS

class Solution {
  public:
    int minValue(Node* root) {
        if(root==NULL) return -1;
        
        Node* temp=root;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp->data;
    }
};

// time complexity : o(h)
// space complexity : o(1)

// link: https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1