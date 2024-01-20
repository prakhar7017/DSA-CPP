// brute force approach
// Time Complexity: O(n^2)
class Solution
{
public:
    bool findtarget(Node* root, int target) {
        if (!root) return false;

        if (root->data == target) return true;

        if (root->data < target) {
            return findtarget(root->right, target);
        }
        if (root->data > target) {
            return findtarget(root->left, target);
        }
        return false;
    }

    void countPairs_Helper(Node* &root1, Node* &root2, int &x, int &ans) {
        if (!root1) {
            return;
        }

        // NLR
        int b = x - root1->data;
        if (findtarget(root2, b)) {
            ans++;
        }
        countPairs_Helper(root1->left, root2, x, ans);
        countPairs_Helper(root1->right, root2, x, ans);
    }

    int countPairs(Node* root1, Node* root2, int x) {
        int ans = 0;
        countPairs_Helper(root1, root2, x, ans);
        return ans;
    }
};
//**************************************************************************************
// Optimized Approach 
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    void buildInorder(Node* root, vector<int>& v) {
        if (!root) {
            return;
        }
        // LNR
        buildInorder(root->left, v);
        v.push_back(root->data);
        buildInorder(root->right, v);
    }
    void buildReverseInorder(Node* root, vector<int>& v) {
        if (!root) {
            return;
        }
        // RNL
        buildReverseInorder(root->right, v);
        v.push_back(root->data);
        buildReverseInorder(root->left, v);
    }

    int countPairs(Node* root1, Node* root2, int x) {
        vector<int> bst1;
        vector<int> bst2;
        buildInorder(root1, bst1);
        buildReverseInorder(root2, bst2);

        int a = 0;
        int b = 0;
        int ans = 0;
        while (a < bst1.size() && b < bst2.size()) {
            int sum = bst1[a] + bst2[b];
           if (sum == x) {
                ans++;
                ++a;
                ++b;
            } else if (sum > x) {
                ++b;
            } else {
                ++a;
            }
        }
        return ans;
    }
};

// optimised approach
// Time Complexity: O(n)
// Space Complexity: O(h1+h2)
// using stack for inorder traversal
class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        int ans=0;
        stack<Node*>s1,s2;
        Node* a=root1;
        Node* b=root2;
        while(1){
            while(a){
                s1.push(a);
                a=a->left;
            }
            while(b){
                s2.push(b);
                b=b->right;
            }
            
            if(s1.empty() || s2.empty()){
                break;
            }
            auto atop=s1.top();
            auto btop=s2.top();
            int sum=atop->data+btop->data;
            if(sum==x){
                ++ans;
                s1.pop();
                s2.pop();
                a=atop->right;
                b=btop->left;
            }
            else if(sum>x){
                s2.pop();
                b=btop->left;
            }else{
                s1.pop();
                a=atop->right;
            }
        }
        return ans;
    }
};

