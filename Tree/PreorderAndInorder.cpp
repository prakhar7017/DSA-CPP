#include <iostream>
#include <queue>
#include <unordered_map>
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

Node* preOrderInorder(int preOrder[],unordered_map<int,int>&mp,int &preOrderIndex,int inOrderStart,int inOrderEnd,int &size){
    //base case
    if(preOrderIndex>=size || inOrderStart>inOrderEnd){
        return NULL;
    }

    // 1 case ma solve karuga
    int element=preOrder[preOrderIndex];
    preOrderIndex++;
    Node* root=new Node(element);
    // element Search
    int position=mp[element];

    // baki recursion dekh lega
    // create left tree
    root->left=preOrderInorder(preOrder,mp,preOrderIndex,inOrderStart,position-1,size);
    // create right tree
    root->right=preOrderInorder(preOrder,mp,preOrderIndex,position+1,inOrderEnd,size);

    return root;
}

Node* postOrderInorder(int postOrder[],unordered_map<int,int>&mp,int &postOrderIndex,int inOrderStart,int inOrderEnd,int &size){
    // base case
    if(postOrderIndex<0 || inOrderStart>inOrderEnd){
        return NULL;
    }
    // 1 case ma solve karuga
    int element=postOrder[postOrderIndex];
    postOrderIndex--;
    Node* root=new Node(element);
    // element Search
    int position=mp[element];

    // baki recursion dekh lega
    root->right=postOrderInorder(postOrder,mp,postOrderIndex,position+1,inOrderEnd,size);
    root->left=postOrderInorder(postOrder,mp,postOrderIndex,inOrderStart,position-1,size);

    return root;
}

int main(){
    // Node *root=createTree();
    // int preOrder[]={2,8,10,6,4,12};
    // int inOrder[]={10,8,6,2,4,12};
    // int size=6;
    // int preOrderIndex=0;
    // int inOrderStart=0;
    // int inOrderEnd=size-1;

    int postOrder[]={8,6,14,4,10,2};
    int inOrder[]={8,14,6,2,10,4};
    int size=6;
    int postOrderIndex=size-1;
    int inOrderStart=0;
    int inOrderEnd=size-1;

    unordered_map<int,int>mp;
    for(int i=0;i<size;i++){
        mp[inOrder[i]]=i;
    }
    // Node *newRoot=preOrderInorder(postOrder,mp,postOrderIndex,inOrderStart,inOrderEnd,size);
    Node *newRoot=postOrderInorder(postOrder,mp,postOrderIndex,inOrderStart,inOrderEnd,size);

    levelOrderTraversal(newRoot);


    return 0;
}
// *************************Important Note*************************
// always remember preorderIndex and postOrderIndex is always pass by reference
// why 
// because we have to update the value of index in every recursive call and if we pass by value then it will not update the value of index in every recursive call as a result while returing from recurisive call we will again use a used preOrderIndex and postOrderIndex
// and we will get wrong answer