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

Node* maxValue(Node*&root){
    if(!root) return NULL;
    Node* temp=root;
    while(temp->right){
        temp=temp->right;
    }

    return temp;
}

Node* minValue(Node*&root){
    if(!root) return NULL;
    Node* temp=root;
    while(temp->left){
        temp=temp->left;
    }

    return temp;
}

bool search(Node*& root,int target){
    if(!root) return false;

    if(root->data==target) return true;

    bool leftAns=false;
    bool rightAns=false;

    if(target<root->data){
        leftAns=search(root->left,target);
    }

    if(target>root->data){
        rightAns=search(root->right,target);
    }

    return leftAns || rightAns;
}

Node* deleteBST(Node* root,int target){
    if(!root) return NULL;

    if(root->data==target){
        if(!root->left && !root->right){
            // leaf node;
            delete root;
            return NULL;
        }else if(root->left && !root->right){
            // only left child exist
            Node* temp=root->left; // left child ko store kara liya
            delete root; // root ko delete kara diya
            return temp; // left child ko return kara diya
        }else if(!root->left&&root->right){
            // only right exist 
            Node* temp=root->right;
            delete root;
            return temp;
        }else{
            // both child exist
            
            // either find maxValue from left or find minValue from right
            Node* maxi=maxValue(root->left);
            // replace root->data with maxi->data
            root->data=maxi->data;
            // delete maxi
            root->left=deleteBST(root->left,maxi->data); // root->left ma se maxi->data ko delete kara do
            return root;
        }
    }else if(target<root->data){
        root->left=deleteBST(root->left,target);
    }else if(target>root->data){
        root->right=deleteBST(root->right,target);
    }
    return root;
}
int main(){
    Node* root=NULL;
    helper(root);
    levelOrderTraversal(root);
    cout<<endl;

    // Node* head=NULL;
    // BST_TO_DLL(root,head);
    // cout<<"output: ";
    // printDLL(head);

    // cout<<endl<<"Max value: "<<maxValue(root)->data;
    // cout<<endl<<"Min value: "<<minValue(root)->data;

    int target;
    cout<<"Enter target: "<<endl;
    cin>>target;
    // while(target!=-1){
    //     bool ans=search(root,target);
    //     if(ans)
    //         cout<<"Found"<<endl;
    //     else 
    //         cout<<"Not Found"<<endl;
    //     cout<<"Enter next target: "<<endl;
    //     cin>>target;
    // }

    while(target!=-1){
        root=deleteBST(root,target);
        levelOrderTraversal(root);
        cout<<"Enter next target: "<<endl;
        cin>>target;
    }
    return 0;
}

// 5 3 7 2 4 6 10 1 8 -1
// 10 5 20 3 7 11 40 -1
