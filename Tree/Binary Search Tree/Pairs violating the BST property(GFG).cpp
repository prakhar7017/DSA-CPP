// Pairs violating the BST property

// Given a binary tree with n nodes, find the number of pairs violating the BST property.
// BST has the following properties:-

// Every node is greater than its left child and less than its right child.
// Every node is greater than the maximum value of in its left subtree and less than the minimum value in its right subtree.
// The maximum in the left sub-tree must be less than the minimum in the right subtree.

// classical example of count inversions
// condition of count inversions:
//                  i<j
//                 arr[i]>arr[j]


class Solution {
  public:
  // genrating inorder traversal of the tree
    void inOrder(Node* root,vector<int>&arr){
        if(root==NULL) return ;
        inOrder(root->left,arr);
        arr.push_back(root->data);
        inOrder(root->right,arr);
    } 
    // mergeing the two sorted array and counting the inversions
    int merge(vector<int>&arr,int s,int mid,int e,vector<int>&temp){
        int leftIndex=s;
        int rightIndex=mid+1;
        int mainIndex=s;
        int c=0;
        while(leftIndex<=mid && rightIndex<=e){
            if(arr[leftIndex]<=arr[rightIndex]){
                temp[mainIndex++]=arr[leftIndex++];
            }else{
                // lieftIndex<rightIndex
                // arr[leftIndex]>arr[rightIndex]
                // both arr the consdition of count invsion
                temp[mainIndex++]=arr[rightIndex++];
                c+=(mid-leftIndex+1);// size of lefindex array
            }
        }
        
        while(leftIndex<=mid){
            temp[mainIndex++]=arr[leftIndex++];
        }
        while(rightIndex<=e){
            temp[mainIndex++]=arr[rightIndex++];
        }
        for(int i=s;i<=e;i++){
            arr[i]=temp[i];
        }
        return c;
    }
    // merge sort
    int mergeSort(vector<int>&arr,int s,int e,vector<int>&temp){
        // basecase
        if(s>=e) return 0;
        
        int mid=s+(e-s)/2;
        int c=0;
        c+=mergeSort(arr,s,mid,temp);
        c+=mergeSort(arr,mid+1,e,temp);
        c+=merge(arr,s,mid,e,temp);
        return c;
    }
    int pairsViolatingBST(int n, Node *root) {
        vector<int>arr;
        inOrder(root,arr);
        
        int size=arr.size();
        int s=0;
        int e=size-1;
        vector<int>temp(size);
        return mergeSort(arr,s,e,temp);
    }
};

// time complexity: O(nlogn)
// space complexity: O(n)

