#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* createBst(Node* &root,int data){
    if(!root){
        Node* createNode=new Node(data);
        return createNode;
    }

    if(data<root->data){
        root->left=createBst(root->left,data);
    }
    if(data>root->data){
        root->right=createBst(root->right,data);
    }

    return root;
}

void helper(Node*& root){
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;

    while(data!=-1){
        root=createBst(root,data);
        cout<<"Enter next Node: "<<endl;
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    if(!root) return ;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front=q.front();
        q.pop();
        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<front->data<<" ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}

void BST_TO_DLL(Node* root,Node*& head){
    if(!root) return;

    //RNL
    //R
    BST_TO_DLL(root->right,head);
    //N
    root->right=head;       // root->right ma right sa ane wali list ka head store kara diya
    if(head) head->left=root; // agar head null nhi hh i.e list ma koi node hh toh toh head ka left pointer ko  root ki traf  point kara do
    head=root; // head ko root par point kara do
    //L
    BST_TO_DLL(root->left,head); // fir left jayenge aur waha bhi same kam karenge
}

void printDLL(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}


int main(){
    Node* root=NULL;
    helper(root);
    levelOrderTraversal(root);

    Node* head=NULL;
    BST_TO_DLL(root,head);
    cout<<"output: ";
    printDLL(head);
    return 0;
}

// 5 3 7 2 4 6 10 1 8 -1
// 10 5 20 3 7 11 40 -1