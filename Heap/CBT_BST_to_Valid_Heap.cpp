#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createBst(Node *&root, int data)
{
    if (!root)
    {
        Node *createNode = new Node(data);
        return createNode;
    }

    if (data < root->data)
    {
        root->left = createBst(root->left, data);
    }
    if (data > root->data)
    {
        root->right = createBst(root->right, data);
    }

    return root;
}

void helper(Node *&root)
{
    int data;
    cout << "Enter data: " << endl;
    cin >> data;

    while (data != -1)
    {
        root = createBst(root, data);
        cout << "Enter next Node: " << endl;
        cin >> data;
    }
}
void levelOrderTraversal(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}

void inorderTraversal(Node *root, vector<int> &v)
{
    if (!root)
        return;
    inorderTraversal(root->left, v);
    v.push_back(root->data);
    inorderTraversal(root->right, v);
}

void replaceusingPostorder(Node *root, vector<int> &v, int &index)
{
    if (!root)
        return;
    // LRN
    // L
    replaceusingPostorder(root->left, v, index);
    // R
    replaceusingPostorder(root->right, v, index);
    // N
    root->data = v[index];
    index++;
}

void levelOrderTraversalConversion(Node *root, int &index, vector<int> &v)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            front->data = v[index--];
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    helper(root);
    vector<int> v;
    inorderTraversal(root, v);
    cout << "Before replacing: " << endl;
    levelOrderTraversal(root);
    cout << endl;
    cout << "after replacing: " << endl;
    replaceusingPostorder(root, v, index);


    // using levelOrderTraversal
    // int index = 0;
    // int n = v.size() - 1;
    // levelOrderTraversalConversion(root, n, v);
    // levelOrderTraversal(root);
    return 0;
}
// 100 50 150 40 60 110 200 20