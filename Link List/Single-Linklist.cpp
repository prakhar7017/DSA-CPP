#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    Node(){
      this->data=0;
      this->next=NULL;
    }

    Node(int data){
      this->data=data;
      this->next=NULL;
    }
    ~Node(){
      cout<<"Destructor called for: "<<this->data<<endl;
    
    }
};

void print(Node* head){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<endl;
}

int findLen(Node* head){
  Node* temp=head;
  int count=0;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
  return count;
}

void insertAtHead(Node* &head, Node* &tail, int data){
  if(head==NULL){
    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
  }else{
    Node* newNode=new Node(data);
    newNode->next=head;
    head=newNode;
  }
}

void insertAtTail(Node* &head, Node* &tail, int data){
  if(head==NULL){
    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
  }else{
    Node* newNode=new Node(data);
    tail->next=newNode;
    tail=newNode;
  }
}

void insertAtPosition(int data,int position,Node* &head,Node* &tail){
  int len=findLen(head);
  if(position<=1){
    insertAtHead(head,tail,data);
    return;
  }else if(position>len){
    insertAtTail(head,tail,data);
    return;
  }else{
    Node* newNode=new Node(data);
    Node* prev=NULL;
    Node* curr=head;
    while(position!=1){
      prev=curr;
      curr=curr->next;
      position--;
    }
    prev->next=newNode;
    newNode->next=curr;
  }
}

void deleteNode(Node* &head,Node* &tail,int position){
  if(head==NULL){
    cout<<"List is empty"<<endl;
  }

  if(head==tail){
    Node* temp=head;
    delete temp;
    head=NULL;
    tail=NULL;
  }
  int len=findLen(head);
    if(position==1){
      Node* temp=head;
      head=head->next;
      temp->next=NULL;
      delete temp;
    }else if(position==len){
      Node* prev=head;
      while(prev->next!=tail){
        prev=prev->next;
      }
      prev->next=NULL;
      delete tail;
      tail=prev;
    }else{
      Node* prev=NULL;
      Node* curr=head;
      while(position!=1){
        prev=curr;
        curr=curr->next;
        position--;
      }
      prev->next=curr->next;
      curr->next=NULL;
      delete curr;
    }
}

int main() {
  Node* head=NULL;
  Node* tail=NULL;

  insertAtPosition(50,1,head,tail);
  insertAtPosition(40,1,head,tail);
  insertAtPosition(30,1,head,tail);
  insertAtPosition(20,1,head,tail);
  insertAtPosition(10,1,head,tail);
  insertAtPosition(60,10,head,tail);
  insertAtPosition(70,10,head,tail);
  insertAtPosition(45,5,head,tail);
  insertAtPosition(65,8,head,tail);
  int len=findLen(head);
  cout<<"before deletion:";
  print(head);

  deleteNode(head,tail,9);
  cout<<"after deletion:";
  print(head);

  return 0;
}