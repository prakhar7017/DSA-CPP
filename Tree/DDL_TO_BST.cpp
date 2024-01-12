#include <iostream>
#include <queue>
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

class ListNode
{
public:
    int data;
    ListNode *prev;
    ListNode *next;

    ListNode(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (!root)
    {
        Node *newNode = new Node(data);
        return newNode;
    }

    if (data < root->data)
    {
        root = insertIntoBST(root->left, data);
    }
    if (data > root->data)
    {
        root = insertIntoBST(root->right, data);
    }
    return root;
}

void createBst(Node *root)
{
    int data;
    cout << "Enter data " << endl;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "enter next node ";
        cin >> data;
    }
}



void InsertIntoDLL(ListNode *&head, ListNode*&  tail, int data)
{
    if (!head)
    {
        ListNode *newNode = new ListNode(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        ListNode *newNode = new ListNode(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void printDLL(Node*&head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->right;
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
        Node *frontNode = q.front();
        if (!frontNode)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << frontNode->data << " ";
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
    }
}

Node* DDL_TO_BST(Node*& head,int n)
{
    // base case
    if(!head || n<=0) return NULL;

    // LNR 
    //L
    Node* leftSubTree=DDL_TO_BST(head,n/2);
    //N
    Node* root=head;
    root->left=leftSubTree;
    head=head->right;

    //r
    Node* rightSubTree=DDL_TO_BST(head,n-n/2-1);
    root->right=rightSubTree;
    return root;
}

int main()
{
    Node *root = NULL;
    Node* head=new Node(1);
    Node* head1=new Node(2);
    Node* head2=new Node(3);
    Node* head3=new Node(4);
    Node* head4=new Node(5);
    head->left=NULL;
    head->right=head1;
    head1->left=head;
    head1->right=head2;
    head2->left=head1;
    head2->right=head3;
    head3->left=head2;
    head3->right=head4;
    head4->left=head3;
    head4->right=NULL;

    printDLL(head);

    Node* ans=DDL_TO_BST(head,5);
    cout<<endl;

    levelOrderTraversal(ans);

    return 0;
}