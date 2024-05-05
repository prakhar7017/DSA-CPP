void solve(Node* root, vector<int>& leftview, int level) {
    if (root == NULL) {
        return;
    }

   
    if (level == leftview.size()) {
        leftview.push_back(root->data);
    }

    solve(root->left, leftview, level + 1);
    solve(root->right, leftview, level + 1);
}
vector<int> leftView(Node *root)
{
    vector<int>lftView;
    int level=0;
    solve(root,lftView,level);
    return lftView;
}

