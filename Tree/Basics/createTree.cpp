#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int _data) : data(_data), left(NULL), right(NULL){};
};

Node *createTree()
{
    cout << "enter value of node " << endl;
    ;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // create Node
    Node *root = new Node(data);

    // create left tree
    cout << "enter left value of : " << root->data << endl;
    root->left = createTree();

    // create right tree
    cout << "enter right vaue of :" << root->data << endl;
    root->right = createTree();

    return root;
}

void preOrderTraversal(Node *root)
{ // NLR
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void inOrderTraversal(Node *root)
{ // LNR
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
void postOrderTraversal(Node *root)
{ // LRN
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout<<endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

int main()
{
    Node *root = createTree();
    //   cout<<root->data<<endl;

    cout << "preOrderTraversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "inOrderTraversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "postOrderTraversal: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "levelOrderTraversal: ";
    levelOrderTraversal(root);
    cout << endl;
    return 0;
}

// 10 20 40 80 -1 -1 90 -1 -1 50 -1 -1 30 60 -1 -1 70 110 -1 -1 120 -1 -1