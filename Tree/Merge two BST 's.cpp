// brute force
class Solution {
public:
    void inOrder(Node* root, vector<int>& v) {
        if (!root) {
            return;
        }
        inOrder(root->left, v);
        v.push_back(root->data);
        inOrder(root->right, v);
    }

    vector<int> merge(Node* root1, Node* root2) {
        vector<int> v1, v2;
        inOrder(root1, v1);
        inOrder(root2, v2);

        int i = 0, j = 0;
        int n = v1.size(), m = v2.size();
        vector<int> ans;

        while (i < n && j < m) {
            if (v1[i] < v2[j]) {
                ans.push_back(v1[i++]);
            } else {
                ans.push_back(v2[j++]);
            }
        }

        while (i < n) {
            ans.push_back(v1[i++]);
        }

        while (j < m) {
            ans.push_back(v2[j++]);
        }

        return ans;
    }
};

// time complexity o(n+m);
// space complexity o(m+m);

//******************************OPTIMISED APPROACH**************************
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int>ans;
        stack<Node*>s1,s2;
        Node* a=root1,*b=root2;
        while(a || b || !s1.empty() || !s2.empty()){
            while(a){
                s1.push(a);
                a=a->left;
            }
            while(b){
                s2.push(b);
                b=b->left;
            }
            if(s2.empty() || (!s1.empty() && s1.top()->data<=s2.top()->data)){
                auto atop=s1.top();
                s1.pop();
                ans.push_back(atop->data);
                a=atop->right;
            }else{
                auto btop=s2.top();
                s2.pop();
                ans.push_back(btop->data);
                b=btop->right;
            }
        }
        return ans;
    }
};

// time complexity o(n);
// space complexity o(n+m);