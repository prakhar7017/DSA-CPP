// brute force solution 
// time complexity O(n^2)
// space complexity O(n)
#include <bits/stdc++.h> 
using namespace std;

int main() {
  vector<int>arr={8,58,71,18,31,32,63,92,43,3,91,93,25,80,28};
  int n=arr.size();
  vector<int>ans(n,-1);
  for(int i=0;i<n;i++){
    int min_greater = INT_MAX;
     for (int j = i + 1; j < n; j++) {
      if (arr[j] > arr[i] && arr[j] < min_greater) {
        min_greater = arr[j];
      }
    }

    ans[i] = (min_greater == INT_MAX) ? -1 : min_greater;
  }

  cout<<endl<<"Print answer"<<endl;
  for(int i=0;i<arr.size();i++){
    cout<<ans[i]<<",";
  }
  return 0;
}

//******************************OPTIMIZED SOLUTION***********************************
// time complexity o(n);
// space complexity o(n);

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int val) : data(val), left(0), right(0){};
};

class Solution
{
public:
  Node *insert(Node *root, int data, int &succ)
  {
    if (!root)
    {
      Node *newNode = new Node(data);
      return newNode;
    }

    if (data >= root->data)
    {
      root->right = insert(root->right, data, succ);
    }
    else
    {
      succ = root->data;
      root->left = insert(root->left, data, succ);
    }
    return root;
  }
  vector<int> findLeastGreater(vector<int> &arr, int n)
  {
    vector<int> ans(arr.size(), -1);
    Node *root = 0;
    for (int i = arr.size() - 1; i >= 0; --i)
    {
      int succ = -1;
      root = insert(root, arr[i], succ);
      ans[i] = succ;
    }
    return ans;
  }
};
